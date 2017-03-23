simple Txc1
{
    gates:
        input in;
        input in2;
        
        output out;
        output out2;
}
//
// Two instances (tic and toc) of Txc1 connected both ways.
// Tic and toc will pass messages to one another.
//
network Tictoc1
{
    submodules:
        tic: Txc1;
        toc: Txc1;
        tac: Txc1;
    connections:
        tic.out --> {  delay = 100ms; } --> toc.in;
     //   tic.in <-- {  delay = 100ms; } <-- toc.out;
       // tic.in2 <-- {  delay = 100ms; } <-- tac.out;
      //  tic.out2 --> {delay = 100ms; } --> tac.in;
      //  toc.in2 <-- {  delay = 100ms; } <-- tac.out2;
        toc.out2 --> {  delay = 100ms; } --> tac.in2;
        tac.out--> { delay = 100ms; } --> tic.in;
        
}
