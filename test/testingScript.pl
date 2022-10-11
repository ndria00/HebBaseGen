#!/usr/bin/perl

$encodings_path = "encodings";
$instances_path = "instances";
$output_path = "output";
$idlv_name = "idlv";
$idlv_path = "";
$generator_path = "../output";
$generator_name = "main";
$generation_option = "generate";

@encodings = qx(ls $encodings_path) || die "Cannot read encodings";

#for all problems in test folder
for $problem_folder(@encodings){
    #print("Hey I found a problem: $problem_folder\n");
    @instances = split(/\s+/, qx(ls $instances_path/$problem_folder) || die "cannot read instances");
    #print @instances;
    chomp($problem_folder);
    #for every instance of a specific problem --> test
    for $instance(@instances){
        #call idlv and store results in this array
        #chomp();
        $path = $instances_path."/".$problem_folder."/".$instance;
        #print("HELLO $path\n");
        @results_i = qx(./$idlv_name $path) || die "Cannot find or execute idlv";
        @results_g = qx(./$generator_path/$generator_name $generation_option $path\n) || die "Cannot find or execute idlv";
        for(@results_g){
            push(@results_generator, split(/\n/));
        
        }
        for(@results_i){
            push(@results_idlv, split(/\n/));
        }
        #print("./$generator_path/$generator_name $generation_option $path\n");
        #create generator for specific problem
        for $generator_tuple(@results_generator){
            $found = 0;
            for $idlv_tuple(@results_idlv){
                if(index($idlv_tuple, $generator_tuple) != -1){
                    $found = 1;
                    print("found $generator_tuple in $idlv_tuple\n");
                }
                else{
                    print("Can't find $generator_tuple in $idlv_tuple\n");
                }
            }
            if($found == 0){
                print("Test failed\n");
            }
            # else{
            #     print("Test passed\n");
            # }
        }
        # for $generator_tuple(@results_generator){
        #     print("GEN $generator_tuple\n");
        # }
        # for $idlv_tuple(@results_idlv){
        #     print(" IDLV $idlv_tuple\n");
        # }
        #compile generator 
        
        #call generator

        #print("$instance in  $instances_path/$problem_folder/$instance  WE\n");
    }
}