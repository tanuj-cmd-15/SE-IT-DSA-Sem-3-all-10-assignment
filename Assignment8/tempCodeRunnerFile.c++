
     distance[i]=r[start][i];
  }
     distance[start]=0;
     visited[start]=1;
     cnt=v;
  while(cnt>0)
  { 
    mindst=9999;
      for(i=0;i<v;i++)     
      {  
          if((mindst > distance[i] )&& visited[i]==0)
           {
               mindst=distance[i];
               next=i;
           }    
      }
 
    visited[next]=1;
    for(i=0;i<v;i++)     
      {
          if(visited[i]==0 && distance[i]>(mindst+r[next][i])) 
          {
             distance[i]=mindst+r[next][i];
             from[i]=next;
           }
      }
        cnt--;