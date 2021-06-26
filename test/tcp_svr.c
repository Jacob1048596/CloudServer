#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
 
void parse(char* buf)
{
    int i,len;
    len=strlen(buf);
    for(i=0;i<len;i++)
    {
        if(buf[i]>='a'&&buf[i]<='z')
        {
            buf[i]=buf[i]-32;
        }
    }
}

int main()
{
    int lfd=socket(AF_INET,SOCK_STREAM,0);
    printf("创建socket成功\n");
    struct sockaddr_in addr;
    addr.sin_family=AF_INET;
    addr.sin_port=htons(2580);
    inet_aton("172.17.213.69",&addr.sin_addr);
    //绑定
    int r=bind(lfd,(struct sockaddr*)&addr,sizeof(addr));
    if(r==-1) perror("bind"),exit(1);
     printf("绑定成功\n");
    //设置被动套接字
    if( (r=listen(lfd,SOMAXCONN))==-1)
        perror("listen"),exit(1);
    printf("设置listen成功\n");
    
    
    //等待连接
    int newfd=accept(lfd,NULL,NULL);
    printf("客户端连接成功\n");
    while(1)
    {
        char buf[1024]={};
        r=read(newfd,buf,1024);
        if(r==0) break;
        printf("data==>%s\n",buf);
        parse(buf);
        printf("data==>%s\n",buf);
        write(newfd,buf,r);

    }
    close(newfd);
    close(lfd);
}