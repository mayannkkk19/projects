#include <iostream>
#include <vector>
using namespace std;

int main () {

    //Sender's side

    string data;
    vector<string> frames;
    int frameSize;
    string flag;
    string header;
    string trailor;
    string sendersData;

    cout<<"Enter the data in bits (i.e. 0, 1): ";
    cin>>data;
    cout<<"Enter frame size: ";
    cin>>frameSize;

    //chunk the string char by char
    int count = 0;
    string temp = "";
    for(auto x: data) {
        temp += x;
        count++;
        if(count == frameSize) {
            frames.push_back(temp);
            temp = "";
            count = 0;
        }
    }

    if(temp != "") frames.push_back(temp);
    count = 0;

    for(auto x: frames) {
        cout<<x<<" ";
    }

    cout<<endl;


    //input flag, header and trailor from the user  
    cout<<"Enter flag: ";
    cin>>flag;
    cout<<"Enter header: ";
    cin>>header;
    cout<<"Enter trailor: ";
    cin>>trailor;

    vector<string> eachFrame;

    string f = "";

    for(auto x: frames) {
        f += flag;
        f += header;
        f += x;
        f += trailor;
        f += flag;

        eachFrame.push_back(f);
        f = "";
    }

    //initialize sendersData to be ready to send
    sendersData = "";
    for(auto x: eachFrame) {
        sendersData += '*';
        sendersData += x;
        sendersData += '*';
    }
    cout<<endl;
    cout<<"Data from sender's side: ";
    cout<<sendersData<<endl;


    //Reciever's side

    //we need to extract data only from sendersData
    //we already know flag, header and trailor part from sendersData
    //each incomming frame is separated by a '*'
    //we can assume each frame is incomming and each has its own flag, header and trailor section

    //to simulate incomming frames on reciever's side
    vector<string> recievedFrames;
    int i = 0;
    string each = "";
    bool check = false;
    while(i < sendersData.size()) {
        if(sendersData[i] == '*') {
            i++;
            if(each != "") recievedFrames.push_back(each);
            each = "";
            continue;
        }
        each += sendersData[i];
        i++;
    }

    cout<<"Inkomming frames on reciever side: "<<endl;
    for(auto x: recievedFrames) {
        cout<<x<<" "<<endl;
    }
    return 0;
}