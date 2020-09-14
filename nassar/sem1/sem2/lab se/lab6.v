module clock(c);
output c;
reg c;
initial
    c=0;
always
    #5 c=~c;
endmodule

module mul(Clk,start,a,b,rezultat,ack);
input Clk,start;
input [3:0]a,b;
output reg [7:0]rezultat;
output reg ack;
reg [3:0]x,y;
reg [2:0]stare;
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
            rezultat<=0;
            stare<=1;
            end
    else if(stare==1)
        begin
        if(y==0)
            begin
            ack<=1;
            stare<=0;
            end
        else
            begin
            rezultat<=rezultat+x;
            y<=y-1;
            end
        end
    else if(stare==2)
        stare<=2;
endmodule

module main();
    reg [3:0]a,b;
    reg start;
    wire clk,ack;
    wire [7:0]r;
    initial
        begin
        $dumpvars(0,main);
        $monitor("time:%d\tstart:%d\ta:%d\tb:%d\tr:%d\tack:%d",$time,start,a,b,r,ack);
        start<=0;
        #2 a<=3;
        b<=4;
        #2 start<=1;
        #10 start<=0;
        #100 $finish();
        end
    mul m(clk,start,a,b,r,ack);
    clock c(clk);
endmodule

