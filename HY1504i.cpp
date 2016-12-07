#include "header.h"
#include <vector>
signed int stricmp (string p1, string p2);
bool isEmpty(shape *head);
void insertFirst(shape *&head,shape *&last);
void insert(shape *&head,shape *&last);
void group(int x,int y,int width,int height);
void recolorElement(int x,int y,int r,int g,int b);
void insertFirstVector(VectorNode *&head1,VectorNode*&last1,VectorNode * temp1);
void insertVector(VectorNode *&head1,VectorNode *&last1,VectorNode * temp1);
bool isEmptyVector(VectorNode *head1);

using namespace std;



struct VectorNode {
    vector <shape> mixalhs;
    VectorNode * next1;
};

void group(int x,int y,int width,int height){
    VectorNode *temp=new VectorNode();
    shape *tmp=head;
    while(tmp!=NULL)
    {
    
        if (stricmp(tmp->Shape,"square")==0){
            square *sq=(square*)tmp;
            if((tmp->x>=x)&&(tmp->x+sq->side<=x+width)&&(tmp->y+sq->side<=y+height)&&(tmp->y>=y))
               temp->mixalhs.push_back(*tmp); 
            
                //mixalhs.push_back(*tmp);
                //cout<<temp->mixalhs.at(0).r<<endl;
        }
        else if(stricmp(tmp->Shape,"rectangle")==0){
            rectangle *rc=(rectangle*)tmp;
            if((tmp->x>=x)&&(tmp->x+rc->width<=x+width)&&(tmp->y>=y)&&(tmp->y+rc->height<=y+height))
               temp->mixalhs.push_back(*tmp);
              
        }
        else if(stricmp(tmp->Shape,"circle")==0){
            circle *cr=(circle*)tmp;
            if ( tmp->x-cr->radius>=x && tmp->y+cr->radius<=y+height && tmp->x+cr->radius <= x+width)
              temp-> mixalhs.push_back(*tmp);
                
        }

        tmp=tmp->next;
        
    }
    insertVector(head1,last1,temp);
    cout<<temp->mixalhs.size()<<endl;
}
bool isEmpty(shape *head){  												//ISEMPTY
    
  if(head==NULL)
      return true;		//checking if my list is empty by head,return bool
    else
      return false;

}
bool isEmptyVector(VectorNode *head1){  												//ISEMPTY
    
  if(head1==NULL)
      return true;		//checking if my list is empty by head,return bool
    else
      return false;

}

void insertFirstVector(VectorNode *&head1,VectorNode*&last1,VectorNode * temp1){							
    temp1->next1=NULL; 
    head1 = temp1;					//inserting the first node of my list
    last1 = temp1;
}

void insertFirst(shape *&head,shape *&last,shape * temp){							
    temp->next=NULL; 
    head = temp;					//inserting the first node of my list
    last = temp;
}
void insertVector(VectorNode *&head1,VectorNode *&last1,VectorNode * temp1){								//INSERT
  if(isEmptyVector(head1))
      {
	  insertFirstVector(head1,last1,temp1);
	  cout<< "Shape Created !"<<endl;
      }
  else								//checking if list is empty,if not,inserts a node					
      {
	  cout<< "Shape Created !"<<endl;
	  temp1->next1=NULL;
	  last1->next1 = temp1;
	  last1 = temp1;
      }
}
void insert(shape *&head,shape *&last,shape * temp){								//INSERT
  if(isEmpty(head))
      {
	  insertFirst(head,last,temp);
	  cout<< "Shape Created !"<<endl;
      }
  else								//checking if list is empty,if not,inserts a node					
      {
	  cout<< "Shape Created !"<<endl;
	  temp->next=NULL;
	  last->next = temp;
	  last = temp;
      }
}

void circle :: makecircle(string mode,int x,int y,int radius,int r,int g,int b){
    if (stricmp(mode,"full")==0){
        for (int i=0 ; i <= 2*radius; i++)
        {
            for (int j=0 ; j <= 2*radius; j++)
            {
                float distcenter = sqrt((i - radius)*(i - radius) + (j - radius)*(j - radius));
                if (distcenter < radius+0.5){
                
                if(!((x + i-radius<0||y-radius + j<0)||(x + i-radius>=CanvWIDTH||y-radius + j>=CanvHEIGHT)))		
                { 
                    Canvas[y + j-radius][x-radius + i] = '*';
                    R[y + j-radius][x-radius + i] = r;
                    G[y + j-radius][x-radius + i] = g;
                    B[y + j-radius][x-radius + i] = b;
                }
                }
            }	
        }
    }
    else if(stricmp(mode,"empty")==0){
        for (int i=0 ; i <= 2*radius; i++)
        {
            for (int j=0 ; j <= 2*radius; j++)
            {
                float distcenter = sqrt((i - radius)*(i - radius) + (j - radius)*(j - radius));
                 if ((distcenter>radius - 0.5)&&(distcenter<radius + 0.5)){
                
                    if(!((x + i-radius<0||y-radius + j<0)||(x + i-radius>=CanvWIDTH||y-radius + j>=CanvHEIGHT)))
                    { 
                        Canvas[y + j-radius][x-radius + i] = '*';
                        R[y + j-radius][x-radius + i] = r;
                        G[y + j-radius][x-radius + i] = g;
                        B[y + j-radius][x-radius + i] = b;
                    }
                }
            }	
        }
}
}

    
void rectangle :: makerectangle(string mode,int x,int y,int width,int height,int r,int g,int b){
   if (stricmp(mode,"full")==0){ 
    for(int i =0;i<width;i++)
    for(int j=0;j<height;j++)
       if(!(x+i<0||y+j<0||x+i>=CanvWIDTH||y+j>=CanvHEIGHT)){
      Canvas[y+j][x+i]='*';						//making of a rectangle,simple
      R[y+j][x+i]=r;						
      G[y+j][x+i]=g;
      B[y+j][x+i]=b;
       }
   }
   else if(stricmp(mode,"empty")==0){
       for(int i =0;i<width;i++)
    for(int j=0;j<height;j++)
       if((i==0)||(i==width)||(j==0)||(j==height)){
      Canvas[y+j][x+i]='*';						//making of a rectangle,simple
      R[y+j][x+i]=r;						
      G[y+j][x+i]=g;
      B[y+j][x+i]=b;
       }
   }
}
       

void square :: makesquare(string mode,int x,int y,int side,int r,int g,int b){									
if (stricmp(mode,"full")==0){
        for (int i=0;i<side;++i){
            for (int j=0;j<side;++j){
                if (!(x+i<0||y+j<0||x+i>=CanvWIDTH||j+y>=CanvHEIGHT)){
                Canvas[y+j][x+i]='*';							
                R[y+j][x+i]=r;
                G[y+j][x+i]=g;
                B[y+j][x+i]=b;
                }
            }
        }
}
else if(stricmp(mode,"empty")==0){
    for (int i=0;i<side;++i){
            for (int j=0;j<side;++j){
                if((i==0)||(i==side-1)||(j==0)||(j==side-1)){
                Canvas[y+j][x+i]='*';							
                R[y+j][x+i]=r;
                G[y+j][x+i]=g;
                B[y+j][x+i]=b;
                }
            }
        }
}
    
}





void printcanv(){														//PRNTCANV
  for (int i=0;i<50;++i){
	  for (int j=0;j<50;++j){
	    cout<<Canvas[i][j];			//no need
	  }
	  cout<<endl;
	}
}

int writeDB (string fname){													//WRITEDB
  std::ofstream myOutfile;
  myOutfile.open (fname.c_str(), std::ofstream::out );
  if (myOutfile.is_open()) 
  {
   myOutfile<< "50" << " " << "50" <<endl;
    for (int i=0;i<50;++i){
      for (int j=0;j<50;++j){
	myOutfile << R[i][j] << " ";
    }
	myOutfile << endl;
    }
    for (int i=0;i<50;++i){
      for (int j=0;j<50;++j){					//save to file,using cstring
	myOutfile << G[i][j] << " ";
      }
	myOutfile << endl;
    }
    for (int i=0;i<50;++i){
      for (int j=0;j<50;++j){
	myOutfile << B[i][j]<< " ";
    }
	myOutfile << endl;
    }
    myOutfile.close();
    return 1;
  }
  return 0;
}

signed int stricmp (string p1, string p2) {											//STRICMP
  unsigned int index=0;
  unsigned int maxIndex=p1.length();
  if (p2.length()<maxIndex) { maxIndex=p2.length(); }
  unsigned char c1, c2;
  do
  {
      
      c1 = (unsigned char) toupper(p1.at(index));
      c2 = (unsigned char) toupper(p2.at(index));
      if (c1 == '\0')							//ex2 function
      {
            return c1 - c2;
      }
   ++index;
   
  }
  while ( (c1 == c2) && (index<maxIndex) );

  if (p1.length()<p2.length()) { return -1; }
  if (p1.length()>p2.length()) { return +1; }

  return c1 - c2;
} 

void recolorElement(int x,int y,int r,int g,int b){							//RECOLOR
  shape *tmp=head;
  while(tmp!=NULL) 
  {
    if (stricmp(tmp->Shape,"square")==0)
	
        {
            square *sq=(square*)tmp;
	  if (tmp->x + sq->side >= x &&tmp->y + sq->side >= y&& tmp->x<=x &&tmp->y<=y)
	    {
	      tmp->r=r;
	      tmp->g=g;
	      tmp->b=b;
	    }
	}
    if (stricmp(tmp->Shape,"circle")==0)
	{
           circle *cr=(circle*)tmp; 
	  if  (cr->radius >= sqrt((x - tmp->x)*(x - tmp->x) + (y - tmp->y)*(y - tmp->y)))  //looping through list,checking if shapes need recolor or not,aiming to next
	    {
	      tmp->r=r;
	      tmp->g=g;
	      tmp->b=b;
	    }
	}
    if (stricmp(tmp->Shape,"rectangle")==0)
	{
            rectangle *rc=(rectangle*)tmp;
	  if ((tmp->x>=x)&&(tmp->y>=y))
	    {
	      tmp->r=r;
	      tmp->g=g;
	      tmp->b=b;
	    }	
	}
    tmp=tmp->next;
  } 
}

void moveElement(int x,int y,int dx,int dy){
  shape *tmp=head;
  while(tmp!=NULL) 
  {
     if(stricmp(tmp->Shape,"square")==0)
      
     {
         square *sq=(square*)tmp;
	if(tmp->x + sq->side >= x &&tmp->y + sq->side >= y&& tmp->x<=x &&tmp->y<=y)
	  {	
	  tmp->x=tmp->x+dx;
	  tmp->y=tmp->y+dy;
	  }
      }
     if(stricmp(tmp->Shape,"circle")==0)
      {
	circle *cr=(circle*)tmp;
          if(cr->radius >= sqrt((x - tmp->x)*(x - tmp->x) + (y - tmp->y)*(y - tmp->y)))		//looping through list checking if shape needs to dx,dy,aiming to next
	  {
	    tmp->x=tmp->x+dx;
	    tmp->y=tmp->y+dy;
	  }
      }
    if(stricmp(tmp->Shape,"rectangle")==0)
      {
          rectangle *rc=(rectangle*)tmp;
	if((tmp->x>=x)&&(tmp->y>=y))
	  {
	    tmp->x=tmp->x+dx;
	    tmp->y=tmp->y+dy;
	  }  
      
    }
    tmp=tmp->next;
  }
}
void printvector(){
    VectorNode*temp=head1;
    while(temp!=NULL){
        cout<<temp->mixalhs.size()<<endl;
        temp=temp->next1;
    }
    }
    
void printlist(){ 														//PRINTLIST
  shape * tmp=head;
  while(tmp!=NULL) 
    {
      if (stricmp(tmp->Shape,"square")==0){
	  square *sq=(square*)tmp;
          cout<< tmp->x <<" " << tmp->y << " " << sq->side<< " " <<tmp->r <<" " <<tmp->g<< " "<<tmp->b << endl;	 
      }
      else if (stricmp(tmp->Shape,"rectangle")==0){
            rectangle *rc=(rectangle*)tmp;
            cout<< tmp->x <<" " << tmp->y << " " << rc->width<< " "<<rc->height<< " " <<tmp->r <<" " <<tmp->g<< " "<<tmp->b << endl;
          
    }
      else if (stricmp(tmp->Shape,"circle")==0){
            circle *cr=(circle*)tmp;
            cout<< tmp->x <<" " << tmp->y << " " << cr->radius<< " " <<tmp->r <<" " <<tmp->g<< " "<<tmp->b << endl;
      }
     tmp=tmp->next;
    }
}

void modCanvas(){														//
  for(int i =0;i<50;i++){
    for(int j=0;j<50;j++){
      Canvas[i][j]='0';
      R[i][j]=255;		//initialize
      G[i][j]=255;
      B[i][j]=255;
    }
    }
}	

int main(){															//MAIN
  
  modCanvas();
  cout << "Welcome to your personal ShapeCreator! \n";
  int done = 0 ;
  while (!done)
    {
      string input = " ";
      string mode= " ";
      string type=" ";
      cout << "Please type a command or hit '?' if you need a complete list of available commands :" <<endl << ">" ;
      getline(cin,input);
      stringstream ss(input);
      ss>>mode;
      cout<<mode<<endl;
       if((stricmp(mode,"full")==0)||(stricmp(mode,"empty")==0)){
         ss>>type;
        if (stricmp(type,"square")==0){  				//SQUARE //simple error checking etc
                string full=mode;
                int x=-1;
                int y=-1;
                int side=-1;
                int r=-1;
                int g=-1;
                int b=-1;
                int flag=-1;
                ss >> x >> y >> side >> r >> g >> b >> flag;
                if (flag!=-1)
                cout<<"Too many arguements!\n";
                else if ((x==-1)||(y==-1)||(side==-1)||(r==-1)||(g==-1)||(b==-1))
                cout<<"Wrong input!\n";
                else{
                        square *tmp=new square();  
                        tmp->full=full;
                        tmp->Shape=type;
                        tmp->x=x;
                        tmp->y=y;
                        tmp->side=side;
                        tmp->r=r;
                        tmp->g=g;
                        tmp->b=b;
                insert(head,last,tmp);
                tmp->makesquare(mode,x,y,side,r,g,b);
                }
	}
	else if(stricmp(type,"rectangle")==0){ 			//RECTANGLE
	    string full= mode;
            int x=-1;
	    int y=-1;
	    int width=-1;
	    int height=-1;
	    int r=-1;
	    int g=-1;
	    int b=-1;
	    int flag=-1;
	    ss >> x >> y >> width >> height >> r >> g >> b >> flag;
	    if (flag!=-1)
		cout<<"Too many arguements!\n";
	    else if ((x==-1)||(y==-1)||(width==-1)||(height==-1)||(r==-1)||(g==-1)||(b==-1))
		cout<<"Wrong input!\n";
	    else
	      {
		rectangle *tmp=new rectangle();
                    tmp->full=full;
                    tmp->Shape=type;
                    tmp->x=x;
                    tmp->y=y;
                    tmp->width=width;
                    tmp->height=height;
                    tmp->r=r;
                    tmp->g=g;
                    tmp->b=b;
		insert(head,last,tmp);
		tmp->makerectangle(mode,x,y,width,height,r,g,b);
	      }
	}
	else if(stricmp(type,"circle")==0){				//CIRCLE
	string full=mode;
        int x=-1;
	int y=-1;
	int radius=-1;
	int r=-1;
	int g=-1;
	int b=-1;
	int flag=-1;
	ss >> x >> y >> radius >> r >> g >> b >> flag;
	if (flag!=-1)
	  cout<<"Too many arguements!\n";
	else if ((x==-1)||(y==-1)||(radius==-1)||(r==-1)||(g==-1)||(b==-1))
	  cout<<"Wrong input!\n";
	else
	{
        circle *tmp=new circle();
                tmp->full=full;
                tmp->Shape=type;
                tmp->x=x;
                tmp->y=y;
                tmp->radius=radius;
                tmp->r=r;
                tmp->g=g;
                tmp->b=b;
	  insert(head,last,tmp);
	  tmp->makecircle(mode,x,y,radius,r,g,b);
	}
      }
       }
      else if (stricmp(mode,"p")==0){				//PRINTVECTOR
	int flag=-1;
	  ss >> flag ;
	  if (flag!=-1)
	  cout<<"Too many arguements!\n";
	  else{
	    printvector();
            //printlist();
	  }
      }
      else if (stricmp(mode,"group")==0){
            int x=-1;
	    int y=-1;
	    int width=-1;
	    int height=-1;
            int flag=-1;
            ss >> x >> y >> width >> height >> flag;
	    if (flag!=-1)
		cout<<"Too many arguements!\n";
	    else if ((x==-1)||(y==-1)||(width==-1)||(height==-1))
		cout<<"Wrong input!\n";
	    else
                group(x,y,width,height);
      }
       else if (stricmp(mode,"q")==0){				//QUIT
	int flag=-1;
	  ss >> flag ;
	  if (flag!=-1)
	  cout<<"Too many arguements!\n";
	  else{
	    done=1;
	  }
       }
       
       else if (stricmp(mode,"recolor")==0){				//RECOLOR
	  int x,y,r,g,b,flag=-1;
	  ss>> x >> y >> r >>g >>b >>flag;
	   if (flag!=-1)
	      cout<<"Too many arguements!\n";
	   else if ((x==-1)||(y==-1)||(r==-1)||(g==-1)||(b==-1))
	      cout<<"Wrong input!\n";
	   else
	      recolorElement(x,y,r,g,b);
	}
       
       else if (stricmp(mode,"move")==0){				//MOVE
	  int x,y,dx,dy,flag=-1;
	  ss>> x >> y >> dx >>dy >>flag;
	  if (flag!=-1)
	  cout<<"Too many arguements!\n";
	else if ((x==-1)||(y==-1)||(dx==-1)||(dy==-1))
	  cout<<"Wrong input!\n";
	else
	  moveElement(x,y,dx,dy);
	}
       else if (stricmp(mode,"save")==0){				//SAVE
	int flag=-1;
	string fname;
	  ss >> fname >>flag ;
	  if (flag!=-1)
	  cout<<"Too many arguements!\n";
	  else if (fname==" ")
	  cout<<"Wrong input!\n"; 
	  else{
	    writeDB (fname);
            printlist();
	  }
	}
       
       else
                cout<< "Uknown Command!"<<endl;
        }
return 0;
}