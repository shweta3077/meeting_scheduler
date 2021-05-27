//Booking A meeting room
/*1) Adding rooms
2) booking slot in a room if available
3) Booking span is of a week
*/
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

class meeting
{
public:
    int start;
    int end;
    meeting(int start,int end)
    {
        this->start = start;
        this->end = end;
    }
};

class room
{
    string room_name;

public:
    vector<vector<meeting>> m_room_meeting;
    room(string name):room_name(name){m_room_meeting.resize(7);}
    string &get_room_name(){return room_name;}
};

class scheduler
{
    vector<room> m_scheduler_room;
public:
    bool book(string room_name, int day, int start,int end);
    void get_room_details();
    void add_room(string room_name);
};

bool scheduler::book(string room_name,int day,int start,int end)
{
    vector<room>::iterator it = find_if(m_scheduler_room.begin(),m_scheduler_room.end(),[room_name](room &r){return r.get_room_name() == room_name;});
    for(auto meet : it->m_room_meeting[day]){
        if(meet.start <end && start< meet.end)
        {
            cout<<"Room "<<room_name<<" not available for timing  "<<start<<"  "<<end<<" on day "<<day<<endl;
            return false;
        }
    }
    it->m_room_meeting[day].push_back(meeting(start,end));
    cout<<"Room "<<room_name<<" booked for timing  "<<start<<"  "<<end<<" on day "<<day<<endl;
    return true;
}

void scheduler::get_room_details()
{
    for(auto &rooms:m_scheduler_room)
    {
        cout<<rooms.get_room_name()<<endl;
    }
}

void scheduler::add_room(string room_name)
{
    room r(room_name);
    m_scheduler_room.push_back(r);

}
int main()
{
    scheduler s;
    s.add_room("phoenix");
    s.add_room("orion");

    s.book("phoenix",1,1,2);
    s.book("phoenix",2,3,4);
    s.book("phoenix",3,1,3);

    return 0;
}
