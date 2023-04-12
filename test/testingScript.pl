#!/usr/bin/perl

$encodings_path = "test/encodings";
$instances_path = "test/instances";
$output_path = "output";
$dlv_name = "dlv2-linux";
$dlv_path = "test/";
$dlv_options = "--wellfounded --no-projection";
$generator_path = "output";
$generator_name = "main";
$generation_option = "generate";
$compilation_option = "compile";
$source_folder_from_curr = ".";

@encodings= split(/\s+/, qx(ls $encodings_path) || die "Cannot read encodings");

if(scalar(@ARGV) >= 0){
    if(shift == "clean"){
        qx(make clean 2>&1);
        print("Clean done\n");
    }
}
#for all problems in test folder
for $problem_folder(@encodings){

    @instances = split(/\s+/, qx(ls $instances_path/$problem_folder) || die "cannot read instances");
    chomp($problem_folder);

    #prepare generator for specific problem
    #make
    qx(make -j8 >/dev/null 2>&1);
    #compile
    qx(./$generator_path/$generator_name $compilation_option  $encodings_path/$problem_folder/$problem_folder.asp 2>/dev/null) || die "cannot compile program";
    
    #for every instance of a specific problem --> test
    for $instance(@instances){
        #call idlv and store results in this array   
        @results_dlv_true = ();
        @results_dlv_undef = ();
        $results_dlv = "";
        $path = $instances_path."/".$problem_folder."/".$instance;
        chomp($path);
        #append instance and encoding to temp file
        qx(cat $encodings_path/$problem_folder/$problem_folder.asp > temp.asp);
        qx(cat $path >> temp.asp);
        $results_dlv = qx(./$dlv_path$dlv_name $dlv_options temp.asp) || die "Cannot find or execute dlv";
        qx(rm temp.asp);
        qx(make -j8 >/dev/null 2>&1);
        print("calling ./$generator_path/$generator_name $generation_option $path\n");
        $results_gen = "";
        $results_gen = qx(./$generator_path/$generator_name $generation_option $path 2>/dev/null) || die "Cannot find or execute generator";

        
        # fill true and udnef maps for hbgen
        @results_gen_true = $results_dlv =~ /True: \{.*\}/g;
        @results_gen_undef = $results_dlv =~ /Undefined: \{.*\}/g;
        %hb_gen_atoms_true;
        %hb_gen_atoms_undef ;
        for $true_block_gen(@results_gen_true){
            @matches = ();
            @matches = $true_block_gen =~ /([a-z_A-Z][0-9a-zA-Z_]*\(.*?\)[\.]?)|([a-z_A-Z][0-9a-zA-Z_]*\(.*?\)[\|]?)/g;
            for $match(@matches){
                if($match ne "" && $match ne " "){
                    if("." eq substr($match, -1) || "." eq substr($match, -1)){
                        chop($match); 
                    }
                    $hb_gen_atoms_true{$match} += 1;
                #print("Added $match to true\n");
                }
            }
        }
        for $undef_block_gen(@results_gen_undef){
            @matches = ();
            @matches = $undef_block_gen =~ /([a-z_A-Z][0-9a-zA-Z_]*\(.*?\)[\.]?)|([a-z_A-Z][0-9a-zA-Z_]*\(.*?\)[\|]?)/g;
            for $match(@matches){
                if($match ne "" && $match ne " "){
                    if("." eq substr($match, -1) || "." eq substr($match, -1)){
                        chop($match); 
                    }
                    $hb_gen_atoms_undef{$match} += 1;
                    #print("Added $match to undef\n");
                }
            }
        }

        #CHECK GEN OUT \in DLV OUT

        #fill true and undef maps for dlv
        @results_dlv_true = $results_dlv =~ /True: \{.*\}/g;
        @results_dlv_undef = $results_dlv =~ /Undefined: \{.*\}/g;
        %dlv_atoms_true;
        %dlv_atoms_undef;
        for $true_block_dlv(@results_dlv_true){
            @matches = ();
            @matches = $true_block_dlv =~ /([a-z_A-Z][0-9a-zA-Z_]*\(.*?\)[\.]?)|([a-z_A-Z][0-9a-zA-Z_]*\(.*?\)[\|]?)/g;
            chomp(@matches);
            for $match(@matches){
                if($match ne "" && $match ne " "){
                    if("." eq substr($match, -1) || "." eq substr($match, -1)){
                        chop($match); 
                    }
                    #print("Added $match to true\n");
                    $dlv_atoms_true{$match} += 1;
                    #check that the atom exists in the data structure that contains
                    #outputs from HBGen 
                    if(!exists $hb_gen_atoms_true{$match}){
                        #when an atom is not found an error has occurred
                        #print in which instance the problem wwas found, on what match and die
                        print("Test failed on-$match- for instannce $instance of problem $problem_folder (the atom was expected to be within the true ones, but it isn't)\n");
                        die "Test FAILED\n";
                    }
                }
            }
        }

        for $undef_block_dlv(@results_dlv_undef){
            @matches = ();
            @matches = $undef_block_dlv =~ /([a-z_A-Z][0-9a-zA-Z_]*\(.*?\)[\.]?)|([a-z_A-Z][0-9a-zA-Z_]*\(.*?\)[\|]?)/g;
            chomp(@matches);
            for $match(@matches){
                if($match ne "" && $match ne " "){
                    if("." eq substr($match, -1) || "." eq substr($match, -1)){
                        chop($match); 
                    }
                    #print("Added $match to undef\n");
                    $dlv_atoms_undef{$match} += 1;
                    #check that the atom exists in the data structure that contains
                    #outputs from HBGen 
                    if(!exists $hb_gen_atoms_undef{$match}){
                        #when an atom is not found an error has occurred
                        #print in which instance the problem wwas found, on what match and die
                        print("Test failed on-$match- for instannce $instance of problem $problem_folder (the atom was expected to be within the undef ones, but it isn't)\n");
                        die "Test FAILED\n";
                    }
                }
            }
        }

        #CHECK DLV OUT \in GEN OUT
        for $gen_true_atom(keys(%hb_gen_atoms_true)){
            #check that the atom exists in the data structure that contains
            #outputs from dlv
            #print("Check True\n"); 
            if(!exists $dlv_atoms_true{$gen_true_atom}){
                #when an atom is not found an error has occurred
                #print in which instance the problem wwas found, on what match and die
                print("Test failed on-$match- for instannce $instance of problem $problem_folder (the atom was expected to be within the undef ones, but it isn't)\n");
                die "Test FAILED\n";
            }

        }
        for $gen_undef_atom(keys(%hb_gen_atoms_undef)){
            #check that the atom exists in the data structure that contains
            #outputs from dlv 
            #print("Check Undef\n"); 
            if(!exists $dlv_atoms_undef{$gen_undef_atom}){
                #when an atom is not found an error has occurred
                #print in which instance the problem wwas found, on what match and die
                print("Test failed on-$match- for instannce $instance of problem $problem_folder (the atom was expected to be within the undef ones, but it isn't)\n");
                die "Test FAILED\n";
            }

        }

        $dlv_tuples_num = keys(%dlv_atoms_true) + keys(%dlv_atoms_undef);
        $gen_tuples_num = keys(%hb_gen_atoms_true) + keys(%hb_gen_atoms_undef); 
        printf("#tuples from dlv: $dlv_tuples_num #tuples from hb_gen $gen_tuples_num\n");
        print("Test for $problem_folder on instance $instance PASSED \n");
        undef %hb_gen_atoms_true;
        undef %hb_gen_atoms_undef;
        undef %dlv_atoms_true;
        undef %dlv_atoms_undef;
        # for $idlv_atom(@results_dlv){
        #     chomp($idlv_atom);
        #     @matches=();
        #     @matches = $idlv_atom =~ /([a-z_A-Z][0-9a-zA-Z_]*\(.*?\)[\.]?)|([a-z_A-Z][0-9a-zA-Z_]*\(.*?\)[\|]?)/g;
        #     #whenever an atom is found in an idlv output rule
        #     for $match(@matches){
        #         #fix
        #         if($match ne "" && $match ne " "){
        #             #if the atom has not been checked
        #             #print("Searching for $match in gen output\n");
        #             if(!exists $checked{$match}){
        #                 $found = 0;
        #                 chomp(@matches);
        #                 if("." eq substr($match, -1) || "." eq substr($match, -1)){
        #                     chop($match); 
        #                 }
        #                 #check that the atom exists in the data structure that contains
        #                 #outputs from HBGen 
        #                 if(exists $hb_gen_atoms{$match}){
        #                     $found = 1;
        #                 }
        #                 #when an atom is not found an error has occurred
        #                 #print in which instance the problem wwas found, on what match and die
        #                 if($found == 0){
        #                     print("Test failed on-$match- for instannce $instance of problem $problem_folder\n");
        #                     die "Test FAILED\n";
        #                 }
        #             }
        #             $checked{$match} = 1;
        #         }
        #     }
        #     print("Test for $problem_folder on instance $instance PASSED \n");
        # }
    }
}
print("All tests PASSED!\n");