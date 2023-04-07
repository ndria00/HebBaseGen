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
        @results_idlv = ();
        %hb_gen_atoms = {};
        %checked = {};
        $path = $instances_path."/".$problem_folder."/".$instance;
        chomp($path);
        #append instance and encoding to temp file
        qx(cat $encodings_path/$problem_folder/$problem_folder.asp > temp.asp);
        qx(cat $path >> temp.asp);
        @results_idlv = qx(./$dlv_path$dlv_name $dlv_options temp.asp) || die "Cannot find or execute idlv";
        qx(rm temp.asp);
        qx(make -j8 >/dev/null 2>&1);
        @results_gen = split(/\n/, qx(./$generator_path/$generator_name $generation_option $path 2>/dev/null) || die "Cannot find or execute generator");
        print("calling ./$generator_path/$generator_name $generation_option $path\n");
        %hb_gen_atoms = ();
        for(@results_gen){
            $hb_gen_atoms{$_} += 1;
        }
        for(@results_i){
            push(@results_idlv, split(/\n/));
        }

        for $idlv_atom(@results_idlv){
            chomp($idlv_atom);
            @matches=();
            @matches = $idlv_atom =~ /([a-z_A-Z][0-9a-zA-Z_]*\(.*?\)[\.]?)|([a-z_A-Z][0-9a-zA-Z_]*\(.*?\)[\|]?)/g;
            #whenever an atom is found in an idlv output rule
            for $match(@matches){
                #fix
                if($match ne "" && $match ne " "){
                    #if the atom has not been checked
                    #print("Searching for $match in gen output\n");
                    if(!exists $checked{$match}){
                        $found = 0;
                        chomp(@matches);
                        if("." eq substr($match, -1) || "." eq substr($match, -1)){
                            chop($match); 
                        }
                        #check that the atom exists in the data structure that contains
                        #outputs from HBGen 
                        if(exists $hb_gen_atoms{$match}){
                            $found = 1;
                        }
                        #when an atom is not found an error has occurred
                        #print in which instance the problem wwas found, on what match and die
                        if($found == 0){
                            print("Test failed on-$match- for instannce $instance of problem $problem_folder\n");
                            die "Test FAILED\n";
                        }
                    }
                    $checked{$match} = 1;
                }
            }
            print("Test for $problem_folder on instance $instance PASSED \n");
        }
    }
}
print("All tests PASSED!\n");