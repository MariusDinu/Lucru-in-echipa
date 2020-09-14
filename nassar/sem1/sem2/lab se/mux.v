module MUX1(Sel,I0,I1,E);
    input Sel,I0,I1;
    output E;
    assign E=(I1&Sel)|(I0&~Sel);
endmodule

module MUX2(Sel,I0,I1,E);
    input Sel,I0,I1;
    output E;
    wire x,y,z;
    not n0(z,Sel);
    and a1(x,I1,Sel);
    and a0(y,I0,z);
    or o0(E,x,y);
endmodule

module MUX3(Sel,I0,I1,E);
    input Sel,I0,I1;
    output E;
    reg E;
    always @(Sel,I0,I1)
    E=(I1&Sel)|(I0&~Sel);
endmodule

module MUX4(Sel,I0,I1,E);
    input Sel,I0,I1;
    output E; reg E;
    always @(Sel,I0,I1)
    begin
    if(Sel==0) E=I0;
    else E=I1;
    end
endmodule

module main();
    reg s,i0,i1;
    wire e1,e2,e3,e4;
    initial
    begin
    $monitor("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d",$time,s,i0,i1,e1,e2,e3,e4);
    s=1;
    i0=1;
    #5 i1=0;
    end
    MUX1 m1(s,i0,i1,e1);
    MUX2 m2(s,i0,i1,e2);
    MUX3 m3(s,i0,i1,e3);
    MUX4 m4(s,i0,i1,e4);
endmodule