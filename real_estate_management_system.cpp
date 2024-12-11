#include<bits/stdc++.h>
using namespace std;
class Commercial;
class Residential;
class Industrial;
class Property_manager;
class Property{
    protected:
    int property_id;
    string location;
    double price;
    string owner_name;
    string contact_num;
    char status;
    static int property_count;
    int static commercial_count;
    int static residential_Count;
    int static industrial_count;
    public:
    Property(){}
    Property(int id, string loc, double p, string on, string cn, char s ){
        property_id=id;
        location=loc;
        price=p;
        owner_name=on;
        contact_num=cn;
        status=s;
        property_count++;
        }
        int get_id(){
        return property_id;
    }
    virtual void display_details(){
       cout<<"Property ID --> "<<property_id<<endl;
       cout<<"Location --> "<<location<<endl;
       cout<<"Price --> "<<price<<endl;
       cout<<"Owner name --> "<<owner_name<<endl;
       cout<<"Contact Number --> "<<contact_num<<endl;
       cout<<"Status --> "<<status<<endl;
    }
    virtual void display_in_line(){
        cout<<left;
        cout<<setw(25)<<property_id<<setw(25)<<location<<setw(25)<<price<<setw(25)<<owner_name<<setw(25)<<contact_num<<setw(25)<<status<<setw(25);
    }
    char get_status()
{
    return status;
}
double get_price(){
    return price;
}
 bool operator>( Property * temp)  {
        return price > temp->price;
    }
    string get_location(){
        return location;
    }
    void getter(int id, string loc, double p, string on, string cn, char s ){
        this->location=loc;
        this->price=p;
        this->owner_name=on;
        this->contact_num=cn;
        this->status=s;
        
    }
    friend void id_in_list(Property_manager * , Property *);
  


};
int Property::property_count=0;
class Commercial :public Property{
    protected:
    string lease_term;
    string annual_tax;
    public:
    friend class Property_manager;
    Commercial(int id, string loc, double p, string on, string cn, char s, string l, string t)
        : Property(id, loc, p, on, cn, s), lease_term(l), annual_tax(t) { 
            commercial_count++;
    }
    void display_details(){
        Property::display_details();
        cout<<"Lease Term in years --> "<<lease_term<<endl;
        cout<<"Annual Property Tax --> "<<annual_tax<<endl;
        cout<<endl<<endl;
    }
    void display_in_line(){
        Property::display_in_line();
        cout<<left;
        cout<<setw(25)<<lease_term<<setw(25)<<annual_tax<<endl;
    }
    friend void specifics(Commercial * o , string l , string a);
    
};
void specifics(Commercial* o,string l , string a){
    o->lease_term=l;
    o->annual_tax=a;
}

int Property::commercial_count=0;
class Residential : public Property{
    protected:
    int bath_num;
    int bed_room;
    public:
    friend class Property_manager;
    Residential(int id, string loc, double p, string on, string cn, char s, int b, int r)
        : Property(id, loc, p, on, cn, s), bath_num(b), bed_room(r) { 
            residential_Count++;
    }
    void display_details(){
        Property::display_details();
        cout<<"Number of bathrooms --> "<<bath_num<<endl;
        cout<<"Number of bedrooms --> "<<bed_room<<endl;
        cout<<endl<<endl;
            
        }
    void display_in_line(){
        Property::display_in_line();
        cout<<left;
        cout<<setw(25)<<bath_num<<setw(25)<<bed_room<<endl;
    }

};
int Property::residential_Count=0;
class Industrial : public Property{
    string area;
    int docks;
    public:
    friend class Property_manager;
    Industrial(int id, string loc, double p, string on, string cn, char s,string a , int d)
    :Property(id, loc, p, on, cn, s), area(a),docks(d){
        industrial_count++;

    }
    void display_details(){
        Property::display_details();
        cout<<"Storage Area available in square feet --> "<<area<<endl;
        cout<<"Number of loading docks available --> "<<docks<<endl;
        cout<<endl<<endl;
    }
    void display_in_line(){
        Property::display_in_line();
        cout<<left;
        cout<<setw(25)<<area<<setw(25)<<docks<<endl;
    }
    void getter(string a, int d){
        area=a;
        docks=d;
    }
};
int Property::industrial_count=0;
class Property_manager: protected Property {
    public:
    vector<Property*> properties;
     Property_manager() {
       cout<<"New list has been created!"<<endl;
    }
    void insert_property(Property* prop){
        bool check=false;
        for(auto it=properties.begin();it!=properties.end();++it){
            if((*it)->get_id()==prop->get_id()){
                cout<<"Property already registered!"<<endl;
                check=true;
                break;

            }
           
        }
        if(check==false){
            properties.push_back(prop);
        }
        
        // properties.push_back(prop);

    }
    void display_all(){
    cout<<left;
    cout<<setw(25)<<"Property ID"<<setw(25)<<"Location"<<setw(25)<<"Price"<<setw(25)<<"Owner Name"<<setw(25)<<" Contact"<<setw(25)<<"Status"<<setw(25)<<"lease/bathroom/area"<<setw(25)<<"tax/bedrooms/docks"<<endl;
    for(auto p:properties){
        p->display_in_line();
       
        }
        cout<<endl<<endl;
}
void display_by_id(int id){
    bool check=false;
    for(auto p:properties){
        if(p->get_id()==id){
            p->display_details();
            check=true;
        }
       
    }
    if(check==false){
        cout<<"Property with the given ID not found!"<<endl;
    }
    cout<<endl<<endl;
}
bool isempty(){
    if(properties.size()==0){
        return true;
    }
    else{
        return false;
    }
    
}
void get_count(){
    cout<<"Number of total Properties --> "<<property_count<<endl;
    cout<<left;
    cout<<setw(15)<<"Commercial"<<setw(15)<<"Residential"<<setw(15)<<"Industrial"<<endl;
    cout<<setw(15)<<commercial_count<<setw(15)<<residential_Count<<setw(15)<<industrial_count<<endl;
    cout<<endl<<endl;
    
}
void get_commercial_list(){
    cout<<left;
    cout<<setw(25)<<"Property ID"<<setw(25)<<"Location"<<setw(25)<<"Price"<<setw(25)<<"Owner Name"<<setw(25)<<" Contact"<<setw(25)<<"Status"<<setw(25)<<"lease_terms"<<setw(25)<<"annual_taxes"<<endl;
    for(auto it:properties){
        if(it->get_status()=='C'){
            it->display_in_line();
        }
    }
    cout<<endl<<endl;
}
void get_residential_list(){
    cout<<left;
    cout<<setw(25)<<"Property ID"<<setw(25)<<"Location"<<setw(25)<<"Price"<<setw(25)<<"Owner Name"<<setw(25)<<" Contact"<<setw(25)<<"Status"<<setw(25)<<"bathroom_count"<<setw(25)<<"bedrooms_count"<<endl;
     for(auto it:properties){
        if(it->get_status()=='R'){
            it->display_in_line();
        }
    }
    cout<<endl<<endl;
}
void get_industrial_list(){
    cout<<left;
     cout<<setw(25)<<"Property ID"<<setw(25)<<"Location"<<setw(25)<<"Price"<<setw(25)<<"Owner Name"<<setw(25)<<" Contact"<<setw(25)<<"Status"<<setw(25)<<"storage_ area"<<setw(25)<<"loading_docks"<<endl;
      for(auto it:properties){
        if(it->get_status()=='I'){
            it->display_in_line();
        }
    }
    cout<<endl<<endl;
}
    void compare(double p1, double p2){
        cout<<"Properites that match your price range are : "<<endl;
        for(auto it:properties){
            if(it->get_price()>=p1&&it->get_price()<=p2){
               it->display_details();
            }

        }
        cout<<endl<<endl;
    }
    void compare(string place){
        for(auto it:properties){
            if(it->get_location()==place){
                it->display_details();
            }
        }
        cout<<endl<<endl;
    }
    void update_property(int id, string loc, double p, string on, string cn, char s){
        bool check=false;
        for(auto it=properties.begin();it!=properties.end();++it){
            if((*it)->get_id()==id){
                 (*it)->getter(id,loc,p,on,cn,s);
                 check=true;
         }
        }
        if(check==true){
        cout<<"Property details updated successfully!"<<endl;
        }
        else{
            cout<<"ID NOT FOUND"<<endl;
        }
        cout<<endl<<endl;
        
    }
   
     void delete_property(int id){
        bool check=false;
         for(auto it=properties.begin();it!=properties.end();++it){
            if((*it)->get_id()==id){
                properties.erase(it);
                check=true;
                break;
            }
        }
        if(check==true){

            cout<<"Property deleted successfully!"<<endl;
        }
        else{
            cout<<"Property not found!"<<endl;
        }
        cout<<endl<<endl;
    }
    friend void id_in_list(Property_manager* , Property *);
   
    
   
};
void id_in_list(Property_manager * l,Property * g){
    bool check=false;
    for(auto it=l->properties.begin();it!=l->properties.end();++it){
            if((*it)->get_id()==g->get_id()){
                cout<<"ID found in the list!"<<endl;
                check=true;
            }
    }
    if(check==false){
        cout<<"ID not found in the list!"<<endl;
    }

}
int main(){
    cout<<"Welcome to my Real Estate Management System!"<<endl;
    cout<<"We have majorly 3 types of estates : "<<endl;
    cout<<"1. Commercial (Status --> C)"<<endl;
    cout<<"2. Residential (Statuss --> R)"<<endl;
    cout<<"3. Industrial (Status --> I)"<<endl;
    cout<<"Operations you can perform are as given below : "<<endl;
    cout<<"1. Display all the properties "<<endl;
    cout<<"2. Insert a property "<<endl;
    cout<<"3. Delete a property "<<endl;
    cout<<"4. Display a property by its ID "<<endl;
    cout<<"5. Update a property info "<<endl;
    cout<<"6. Display all the commercial properties from the list "<<endl;
    cout<<"7. Dsiplay all the residential properties from the list "<<endl;
    cout<<"8. Display all the industrial properties from the list "<<endl;
    cout<<"9. Get count of properties in the input property list "<<endl;
    cout<<"10. Find properties in the given price range (2 inputs ) "<<endl;
    cout<<"11. Find properties as per your given location "<<endl;
    cout<<"12. Check if the property list is empty "<<endl;
    cout<<"13 .EXIT"<<endl;
    vector<Property_manager*> prop_lists;
    Property * obj1=new Commercial(2314,"Thane",2000000,"Bhumika","9653214568",'C',"10","20000");
    Property * obj2=new Commercial(9734,"Thane",5500000,"Sachi","9962145879",'C',"15","40000");
    Property * obj3=new Residential(1980,"Mumbai",6500000,"Tanmay","9954783259",'R',2,2);
    Property * obj4=new Residential(3980,"Vasai",4500000,"Kalpanika","9974625896",'R',2,3);
    Property * obj5=new Industrial(2900,"Andheri",8000000,"Sakharam","9965842569",'I',"7000",5);
    
    if(obj1>obj2){
        cout<<"The price of property with the id "<<obj1->get_id()<<" is greater than the price of the property with id "<<obj2->get_id()<<endl;
    }
    else{
        cout<<"The price of property with the id "<<obj2->get_id()<<" is greater than the price of the property with id "<<obj1->get_id()<<endl;

    }
    Property_manager * list1;
    list1->insert_property(obj1);
    list1->insert_property(obj2);
    list1->insert_property(obj3);
    list1->insert_property(obj4);
    list1->insert_property(obj5);
    list1->display_all();
    list1->display_by_id(67);
    list1->display_all();
    list1->get_commercial_list();
    list1->get_industrial_list();
    list1->update_property(67,"surat",600000,"TEJAS","5676351894683",'C');
     list1->display_all();
     id_in_list(list1 , obj2);

    int k=1;
    while(k!=0){
        cout<<"Enter the preferred operation number: ";
        cin>>k;
        switch(k){
            case 1:{
                list1->display_all();
                break;

                
            }
            case 2:{
                 int property_id;
                 string location;
                 double price;
                 string owner_name;
                 string contact_num;
                 char s;
                 cout<<"Enter the property_id --> ";
                 cin>>property_id;
                 cout<<"Enter the location of the property --> ";
                 cin>>location;
                 cout<<"Enter the price of the property --> ";
                 cin>>price;
                 cout<<"Enter the owner's name --> ";
                 cin>>owner_name;
                 cout<<"Enter the contact number --> ";
                 cin>>contact_num;
                 cout<<"Enter the status i.e "<<endl<<"C for Commercial"<<endl<<"R for Residential"<<endl<<"I for Industial";
                 cin>>s;
                 if(s=='C'){
                    string lease;
                    string annual_tax;
                    cout<<"Enter the lease term for the property --> ";
                    cin>>lease;
                    cout<<"Enter the annual tax of the property --> ";
                    cin>>annual_tax;
                    Property * c=new Commercial(property_id,location,price,owner_name,contact_num,s,lease,annual_tax);
                    list1->insert_property(c);
                    
                 }
                 else if(s=='R'){
                    int bed;
                    int bath;
                    cout<<"Enter the number of bathrooms --> ";
                    cin>>bath;
                    cout<<"Enter the number of bedrooms --> ";
                    cin>>bed;
                    Property * r= new Residential(property_id,location,price,owner_name,contact_num,s,bath,bed);
                    list1->insert_property(r);

                 }
                 else if(s=='I'){
                    string area;
                    int docks;
                    cout<<"Enter the area of the industrial property --> ";
                    cin>>area;
                    cout<<"Enter the number of docks available --> ";
                    cin>>docks;
                   Property *i1= new Industrial(property_id,location,price,owner_name,contact_num,s,area,docks);
                    list1->insert_property(i1);
                    
                 }
                 else{
                    cout<<"Wrong status input"<<endl;
                 }
                 break;
                
            }
            case 3:{
                int id;
                cout<<"Enter the property id of the property to be deleted --> ";
                cin>>id;
                list1->delete_property(id);
                break;

            }
            case 4:{
                int id;
                cout<<"Enter the ID whose details are to be seen --> ";
                cin>>id;
                list1->display_by_id(id);
                break;

            }
            case 5:{
                 int property_id;
                 string location;
                 double price;
                 string owner_name;
                 string contact_num;
                 char status;
                 cout<<"Enter the property_id of the property whose details are to be updated --> ";
                 cin>>property_id;
                 cout<<"Enter the location of the property --> ";
                 cin>>location;
                 cout<<"Enter the price of the property --> ";
                 cin>>price;
                 cout<<"Enter the owner's name --> ";
                 cin>>owner_name;
                 cout<<"Enter the contact number --> ";
                 cin>>contact_num;
                 cout<<"Enter the status i.e "<<endl<<"C for Commercial"<<endl<<"R for Residential"<<endl<<"I for Industial";
                 cin>>status;
                list1->update_property(property_id,location,price,owner_name,contact_num,status);
                 break;
            }
            
            case 6:{
               list1->get_commercial_list();
                break;

            }
            case 7:{
                list1->get_residential_list();
                break;
            }
            case 8:{
                list1->get_industrial_list();
                break;

            }
            case 9:{
                list1->get_count();
                break;
            }
            case 10:{
                int s,e;
                cout<<"Enter the starting price --> ";
                cin>>s;
                cout<<"Enter the ending price --> ";
                cin>>e;
                list1->compare(s,e);
                break;
                

            }
            case 11:{
                string place;
                cout<<"Enter your preferred location -->";
                cin>>place;
                list1->compare(place);
                            
                            }
                            break;
            
            case 12:{
                if(list1->isempty()){
                    cout<<"This list is empty"<<endl;

                }
                else{
                    cout<<"The list is not empty"<<endl;
                }
                cout<<endl<<endl;
                break;
            }
          case 13:{
                exit(0);
            }
           
        }
        
       
    }
    



    return 0;

}
