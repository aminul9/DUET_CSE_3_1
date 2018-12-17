


#include <bits/stdc++.h>
using namespace std;

struct point{
    int x,y;
    point(){}
    point(int x,int y){this->x=x;this->y=y;}

};


int dist(int x1,int y1,int x2,int y2,int px,int py)
{
    return (px-x1)*(y1-y2) - (x1-x2)*(py-y1);

}

point arr[100];
bool vis[100][100];
vector<point>result;
int N;


void Fill_Triangle(int minx,int miny,int maxx,int maxy,int nx,int ny)
{


    vis[nx][ny]=true;

    for(int i=1;i<=N;i++)
    {
        if( !vis[arr[i].x] [arr[i].y])
        {
            if(dist(minx,miny,maxx,maxy,arr[i].x,arr[i].y) >=0 and dist(maxx,maxy,nx, ny,arr[i].x,arr[i].y)>=0  and dist(nx, ny,minx,miny,arr[i].x,arr[i].y)>=0 )
               {
                    vis[arr[i].x][arr[i].y]=true;
                    //cout<<arr[i].x<<" "<<arr[i].y<<endl;
               }
            else if(dist(minx,miny,maxx,maxy,arr[i].x,arr[i].y) <=0 and dist(maxx,maxy,nx, ny,arr[i].x,arr[i].y)<=0  and dist(nx, ny,minx,miny,arr[i].x,arr[i].y)<=0 )
               {
                    vis[arr[i].x][arr[i].y]=true;

               }
        }

    }

}
 bool chk=false;
void convexhull(int minx,int miny,int maxx,int maxy)
{
      int nx=INT_MAX,ny;

      int dis=0;
      for(int i=1;i<=N;i++ )
      {
            int temp=dist(minx,miny,maxx,maxy,arr[i].x,arr[i].y);

            if(dis<temp  && vis[ arr[i].x ][ arr[i].y]==false)
                {

                    dis=temp;
                    nx=arr[i].x;
                    ny=arr[i].y;

                }
      }

           //Fill the inside The Generate Triangle Element
      if(nx!= INT_MAX)
      {
          result.push_back(point(nx,ny));
          Fill_Triangle( minx, miny, maxx, maxy, nx, ny);
          convexhull(minx, miny, maxx, maxy);
      }

      else{
              if(chk==false)
                {
                    result.push_back(point(maxx,maxy));
                    chk=true;
                }

            for(int i=1;i<=N;i++ )
                {
                        int temp=dist(minx,miny,maxx,maxy,arr[i].x,arr[i].y);

                        if(dis>temp  && vis[ arr[i].x ][ arr[i].y]==false)
                        {
                            dis=temp;
                            nx=arr[i].x;
                            ny=arr[i].y;
                        }
                }

                if(nx!= INT_MAX)
                {

                    result.push_back(point(nx,ny));
                        Fill_Triangle( minx, miny, maxx, maxy, nx, ny);
                            convexhull(minx, miny, maxx, maxy);
                    }

      }

}


int main()
{
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    cin>>N;
    int maxx=INT_MIN,maxy=INT_MIN,minx=INT_MAX,miny;

    for(int i=1;i<=N;i++)
    {
        cin>>arr[i].x>>arr[i].y;

        if(arr[i].x >=maxx  )
            {
                 if(maxx==arr[i].x) maxy=max(arr[i].y,maxy);
                 else {maxx=arr[i].x  ; maxy=arr[i].y;}
            }
        if(arr[i].x <=minx ) {
                if(minx==arr[i].x) miny=min(arr[i].y,miny);
                else  minx=arr[i].x, miny=arr[i].y;
                }
    }



    result.push_back( point(minx,miny));  //&& arr[i].y >maxy  && arr[i].y<miny
    vis[minx][miny]=true;
    vis[maxx][maxy]=true;


    convexhull(minx,miny,maxx,maxy);   //function calling




    result.push_back( point(minx,miny));

    cout<<endl<<endl<<endl;
    cout<<" (start) -->";
    for(vector<point>::iterator it=result.begin();it!=result.end();++it)
    {
            int x=it->x;
            int y=it->y;
            printf(" (%d,%d)----> ",x,y);

    }
    cout<<" (End)\n\n\n";


    return 0;
}
