module clock(c);
output c;
reg c;
initial
    c=0;
always
    #5 c=~c;
endmodule

module euclid(Clk,start,a,b,y,ack);
input Clk,start;
input [7:0]a,b;
output reg ack;

reg [7:0] x;
output reg [7:0]y;
reg [3:0] stare;

initial
    stare<=0;
always @(Clk)
    if(stare==0)
        if(start==0)
            begin
            ack<=0;
            stare<=0;
            end
        else 
            begin
            x<=a;
            y<=b;
            stare<=1;
            end
    else if(stare==1)
        if(x==y)
            stare<=2;
        else if(x>y)
            x<=x-y;
        else
            y<=y-x;
    else if(stare==2)
        begin
        ack<=1;
        if(start==0)
            stare<=0;
        else
            stare<=2;
        end
endmodule

module main();
    reg [0:7] a,b;
    reg start;
    wire clk,ack;
    wire [0:7] r;

    initial
    begin
        $monitor("time:%d\tstart:%d\ta:%d\tb:%d\tr:%d\tack:%d",$time,start,a,b,r,ack);
        start<=0;
        a<=10;
        #2 b<=24;
        #10 start=1;
        #100 start=0;
        a<=11;
        b<=33;
        #10 start=1;

    end
    euclid m(clk,start,a,b,r,ack);
    clock c(clk);
endmodule
