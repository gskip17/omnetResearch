#include <string.h>
#include <omnetpp.h>

using namespace omnetpp;

class Txc1 : public cSimpleModule {
    protected:
        virtual void initialize() override;
        virtual void handleMessage(cMessage *msg) override;
};

// The module needs to be registered with OMNet++
Define_Module(Txc1);

void Txc1::initialize(){
    // Initialize is called at the beginning of the simulation.
    // To bootstrap the tic-toc-tic-toc process, one of the modules needs
    // to send the first message. Let this be `tic'

    //Am I Tic or Toc?
    if (strcmp("tic", getName()) == 0) {
            // create and send first message on gate "out". "tictocMsg" is an
            // arbitrary string which will be the name of the message object.
            cMessage *msg = new cMessage("tictocMsg");
            send(msg, "out");
        }

    if (strcmp("tac", getName()) == 0) {
                // create and send first message on gate "out". "tictocMsg" is an
                // arbitrary string which will be the name of the message object.
                cMessage *msg = new cMessage("tictocMsg");
                send(msg, "out");
            }
}

void Txc1::handleMessage(cMessage *msg){
    send(msg, "out");
}



