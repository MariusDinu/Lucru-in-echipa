module clock(c);
output c;
reg c;
initial
    c=0;
always
    #2 c=~c;
endmodule

module main();
    wire cc;
    initial
    begin
    $display("\t\tTime\tcc");
    $monitor("%d\t%d",$time,cc);
    #50 $finish();
    end
    clock clk(cc);
endmodule