#include<iostream>
#include<vector>
#include<iterator>
#include<list>

using namespace std;


class Edge{
    public:
        int DestinationVertexID;
        int weight;

        Edge(){

        }


        Edge(int destVID, int w){
            DestinationVertexID = destVID;
            weight = w;
        }


        void setEdgeValues(int destVID, int w){
            DestinationVertexID = destVID;
            weight= w;
        }

        void setWeight(int w){
            weight = w;
        }

        int getDestinationVertexID(){
            return DestinationVertexID;
        }

        int getWeight(){
            return weight;
        }

};

class Vertex{
    public:
    int state_id;
    string state_name;

    list<Edge> edgeList;

    Vertex(){
        state_id = 0;
        state_name = "";
    }

    Vertex(int id, string sname){
        state_id = id;
        state_name = sname;
    }

    int getStateID(){
        return state_id;
    }

    string getStateName(){
        return state_name;
    }

    void setID(int id){
        state_id = id;
    }

    void setStateName(string sname){
        state_name = sname;
    }

    list<Edge> getEdgeList(){
        return edgeList;
    }

    

    void printEdgeList(){
        cout<<" [";
        
        for(auto it=edgeList.begin(); it != edgeList.end();it++){
            cout<<it->getDestinationVertexID()<<" ("<<it->getWeight()<<" ) -->";
        }
        cout<<" ]"<<endl;
    }

};

class Graph{
    public:
    vector<Vertex> vertices;

    // Graph(){

    // }

    void addVertex(Vertex newVertex){
        bool check = checkIfVertexExistByID(newVertex.getStateID());

        if(check == true)
        cout<<"Vertex with this Id already exist "<<endl;

        else{
            vertices.push_back(newVertex);
            cout<<"New Vertex Added Successfully"<<endl;
        }

    }

    bool checkIfVertexExistByID(int vid){
        bool flag = false;

        for(int i=0;i<vertices.size();i++){
            if(vertices.at(i).getStateID() == vid)
            return true;
        }

        return false;
    }

    bool checkIfEdgeExistByID(int fromVertex, int toVertex){
        Vertex v = getVertexByID(fromVertex);
        list <Edge> e;

        e = v.getEdgeList();
        bool flag = false;
        for(auto it= e.begin();it != e.end();it++){
            if(it->getDestinationVertexID() == toVertex){
                flag = true;
                return flag;
                break;
            }
        }
        return flag;
    }

    void addEdgeByID(int fromVertex, int toVertex, int weight){
        bool check1 = checkIfVertexExistByID(fromVertex);

        bool check2 = checkIfVertexExistByID(toVertex);

        if(check1 && check2 == true){
            bool check3 = checkIfEdgeExistByID(fromVertex, toVertex);

            if(check3 == true){
                cout<<"Edge between "<<getVertexByID(fromVertex).getStateName()<<"("<<fromVertex<<" ) and"<<getVertexByID(toVertex).getStateName()<<" ("<<toVertex<<" ) Already Exist\n";
            }

            else{
                for(int i=0;i<vertices.size();i++){
                    if(vertices.at(i).getStateID() == fromVertex){
                        Edge e(toVertex, weight);
                        vertices.at(i).edgeList.push_back(e);
                    }

                    else if(vertices.at(i).getStateID() == toVertex){
                        Edge e(fromVertex, weight);
                        vertices.at(i).edgeList.push_back(e);
                    }
                }
                cout<<"Edge between "<<fromVertex<<" and"<<toVertex<<"Created Successfully\n";
            }
        }
        else
        cout<<"Invalid vertex id\n";
    }

    

    Vertex getVertexByID(int vid){
        Vertex temp;
        for(int i=0;i<vertices.size();i++){
            temp= vertices.at(i);
            if(temp.getStateID() == vid)
                return temp;
        }
    }

    void updateEdgeByID(int fromVertex, int toVertex, int newWeight){

        bool check = checkIfEdgeExistByID(fromVertex, toVertex);

        if(check == true){

            for(int i=0;i<vertices.size();i++){

                if(vertices.at(i).getStateID() == fromVertex){
                    for(auto it = vertices.at(i).edgeList.begin(); it != vertices.at(i).edgeList.end(); it++){
                        if(it->getDestinationVertexID() == toVertex){
                        it->setWeight(newWeight);
                        break;
                        }
                    }
                }

                else if(vertices.at(i).getStateID() == toVertex){
                    for(auto it = vertices.at(i).edgeList.begin(); it != vertices.at(i).edgeList.end(); it++){
                        if(it->getDestinationVertexID() == fromVertex){
                        it->setWeight(newWeight);
                        break;
                        }
                    }
                }
            }
            cout<<"Edge Weight Updated Successfully \n";
        }

        else{
            cout<<"Edge between vertex "<<fromVertex <<"and vertex "<<toVertex <<"does not exist \n";
        }
    }

    void deleteEdgeByID(int fromVertex, int toVertex ){

        bool check = checkIfEdgeExistByID(fromVertex, toVertex);

        if(check == true){

            for(int i=0;i<vertices.size();i++){

                if(vertices.at(i).getStateID() == fromVertex){

                    for(auto it = vertices.at(i).edgeList.begin(); it != vertices.at(i).edgeList.end(); it++){
                        if(it->getDestinationVertexID() == toVertex){
                        vertices.at(i).edgeList.erase(it);
                        break;
                        }
                    }
                }

                else if(vertices.at(i).getStateID() == toVertex){

                    for(auto it = vertices.at(i).edgeList.begin(); it != vertices.at(i).edgeList.end(); it++){
                         if(it->getDestinationVertexID() == fromVertex){
                        vertices.at(i).edgeList.erase(it);
                        break;
                         }
                    }
                }
            }
            cout<<"Edge Deleted Successfully \n";
        }

        else
            cout<<"Edge between vertex "<<fromVertex <<"and vertex "<<toVertex <<"does not exist \n";

    }

    void deleteVertexByID(int vid){
        int vIndex = 0;

        for(int i=0;i<vertices.size();i++){
            if(vertices.at(i).getStateID() == vid)
                vIndex = i;
        }

        for(int i=0;i<vertices.size();i++){
            if(checkIfEdgeExistByID(vertices.at(i).getStateID(), vid) == true)
                deleteEdgeByID(vertices.at(i).getStateID(), vid);
        }

        vertices.erase(vertices.begin()+vIndex);

        cout<<"Vertex Deleted Successfully \n\n";
    }

    void updateVertex(int vid, string vname){

        bool check = checkIfVertexExistByID(vid);

        if(check == true){

            for(int i=0;i<vertices.size();i++){

                if(vertices.at(i).getStateID() == vid){
                    vertices.at(i).setStateName(vname);
                    break;
                }
            }
        }
    }
    

    void printGraph(){

        for(int i=0;i<vertices.size();i++){
            Vertex temp;
            temp = vertices.at(i);
            cout<<temp.getStateName()<<" ("<<temp.getStateID()<<") -->";
            temp.printEdgeList();
        }
    }
};


int main(){
    system("cls");

    //Edge e1;
    //e1.setValues()
    //e1.getValues()

    Graph g;
    
    int option, id1, id2, w;
    string sname;
    Vertex v1;

    do{

        cout<<"What opertaion do you want to perform? "<<" Select option number. Enter 0 to exit. "<<endl;
        cout<<"1. Add Vertex"<<endl;
        cout<<"2. Update Vertex"<<endl;
        cout<<"3. Delete Vertex"<<endl;
        cout<<"4. Add Edge"<<endl;
        cout<<"5. Update Edge"<<endl;
        cout<<"6. Delete Edge"<<endl;
        cout<<"7. Check if 2 vertices are Neighbours"<<endl;
        cout<<"8. Print All Neighbours of a Vertex"<<endl;
        cout<<"9. Print Graph"<<endl;
        cout<<"10. Clear Screen"<<endl;
        cout<<"0. Exit program"<<endl;

        cin>>option;

        switch(option){
            case 0:
                break;

            case 1:
                cout<<"Add Vertex operation - "<<endl;
                cout<<"Enter State ID: ";
                cin>>id1;

                cout<<"Enter State Name: ";
                cin>>sname;

                v1.setID(id1);
                v1.setStateName(sname);
                g.addVertex(v1);

                break;

            case 2:
                cout<<"Update Vertex operation - "<<endl;

                cout<<"Enter the id of the Vertex to be Updated: ";
                cin>>id1;

                cout<<"Enter the new name to of the Vertex: ";
                cin>>sname;

                g.updateVertex(id1, sname);

                break;

            case 3:
                cout<<"Delete Vertex operation - "<<endl;

                cout<<"Enter the vertex ID to be Deleted: ";
                cin>>id1;

                g.deleteVertexByID(id1);

                break;

            case 4:
                cout<<"Add Edge operation - "<<endl;

                cout<<"Enter ID of Source Vertex(State): ";
                cin>>id1;
                cout<<"Enter ID of Destination Vertex(State): ";
                cin>>id2;

                cout<<"Enter weight of Edge: ";
                cin>>w;
                g.addEdgeByID(id1, id2, w);
                break;

            case 5:
                cout<<"Update Edge operation - "<<endl;
                cout<<"Enter the id of source vertex: \n";
                cin>>id1;

                cout<<"Enter the id of destinattion vertex: \n";
                cin>>id2;

                cout<<"Enter the new weight: \n";
                cin>>w;

                g.updateEdgeByID(id1, id2, w);

                break;

            case 6:
                cout<<"Delete Edge operation - "<<endl;

                cout<<"Enter the id of source vertex: ";
                cin>>id1;

                cout<<"Enter the id of destination vertex: ";
                cin>>id2;

                g.deleteEdgeByID(id1, id2);

                break;

            case 7:
                cout<<"Check if 2 vertices are neighbours - "<<endl;

                break;

            case 8:
                cout<<"Print All Neightbours of a Vertex - "<<endl;

                break;

            case 9:
                cout<<"Pritn Graph operation - "<<endl;
                g.printGraph();

                break;
            
            case 10:
                system("cls");

                break;

            default:
                cout<<"Enter proper option number: ";

                break;
        }

    }while(option != 0);
    
    
    return 0;
}