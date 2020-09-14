module clock(c);
output c;
reg c;
initial
    c=0;
always
    #2 c=~c;
endmodule

module RAM(Clk,rd,wr,addr,data,data2);
    input Clk,rd,wr;
    input [7:0]addr;
    input [7:0]data2;
    output reg [7:0]data;
    reg [7:0]a;
    reg [7:0]mem[255:0];
    reg [8:0]stare;
    integer i;
    initial
    begin
        stare=0;
        data<=8'bzzzzzzzz;
        for(i=0;i<256;i=i+1)
            mem[i]<=255-i;
    end
    always@(posedge Clk)
    begin
        if(stare==0)
            if(rd==0 && wr==0)
                stare<=0;
            else
            begin
                a<=addr;
                if(rd==1)
                    stare<=1;
                else if (wr==1)
                    stare<=5;
            end
        else if(stare==1)
            stare<=2;
        else if(stare==2)
        begin
            data<=mem[a];
            stare<=3;
        end
        else if(stare==3)
            stare<=4;
        else if(stare<=4)
        begin
            data<=8'bzzzzzzzz;
            stare<=0;
        end
        else if(stare==5)
            stare<=6;
        else if(stare==6)
        begin
            mem[a]=data2;
            stare<=7;
        end
        else if(stare==7)
            stare<=8;
        else if(stare==8)
        begin
            stare<=0;
        end;

    end
endmodule
module main();
    reg [0:7]addr;
    reg read,write;
    reg [0:7]data2;
    wire [0:7]data;
    wire clk;
    initial 
    begin
        $dumpvars(0,main);
        $monitor("time:%d\tread:%d\taddr:%d\tdata:%d\twrite:%d",$time,read,addr,data,write);
        data2=123;
        addr<=10;
        read<=0;
        write<=0;
        #2 write<=1;
        #10 write<=0;
        #10 read<=1;
        #10 read<=0;
        #100 $finish();
    end
    RAM r(clk,read,write,addr,data,data2);
    clock ceas(clk);
endmodule