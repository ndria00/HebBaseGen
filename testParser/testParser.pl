#!/usr/bin/perl
$grammar_name = "ASPCore2";
$root_rule = "program";
$option = "tree";
$tests_location = "tests";

$all_succeded = 1;
@out = qx(ls $tests_location);

for $file_name (@out){
    #if the current file is an input file launch
    #the test and verify the output with the
    #content of the corresponding output file
    if($file_name =~ /(input_)(test(\d+))/){
        $outputfile_name = "output_".$2;
        $test_name = $2;
        grep(/^$outputfile_name$/, @out) || die "Error: Output file not found for test $file_name";
        $output = qx(java org.antlr.v4.gui.TestRig $grammar_name $root_rule -$option <tests/$file_name);
        $expected_output = "";
        open($file_out, "<", "tests/$outputfile_name") || die "Error: cannot open file";
        while(<$file_out>){
            $expected_output = $expected_output.$_;
        }

        if($output eq $expected_output){
            print("$test_name ---> SUCCESSFUL\n");
        }
        else{
            print("$test_name ---> FAILED\n");
            $all_succeded = 0;
        }
        close($file_out)
    }
}

if($all_succeded == 1){
   print("ALL TESTS PASSED\n");
}
else{
    print("SOME TESTS FAILED\n");
}