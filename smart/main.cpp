#include<iostream>
#include"data.hpp"
#include<mysql/mysql.h>
#define _CRT_SECURE_NO_WARNINGS 1

#define MYSQL_HOST "0.0.0.0"
//#define MYSQL_PORT "3306"
#define MYSQL_USER "root"
#define MYSQL_PSWD "114514"
#define MYSQL_DB "smarthome"
#include<mutex>
std::mutex _mutex;
MYSQL* MysqlInit()//初始化0
{
    MYSQL* mysql;
    //初始化
    mysql = mysql_init(NULL);
    if (mysql == NULL)
    {
        printf("init mysql error\n");
        return NULL;
    }
    //连接服务器
    if (mysql_real_connect(mysql, MYSQL_HOST, MYSQL_USER, MYSQL_PSWD, NULL, 0, NULL, 0) == NULL)
    {
        printf("connect mysql error :%s\n", mysql_error(mysql));
        mysql_close(mysql);
        return NULL;
    }
    //选择字符集
    if (mysql_set_character_set(mysql, "utf8") != 0)
    {
        printf("connect mysql error :%s\n", mysql_error(mysql));
        mysql_close(mysql);
        return NULL;
    }
    //选择数据库
    if (mysql_select_db(mysql, MYSQL_DB) != 0)
    {
        printf("select db error :%s\n", mysql_error(mysql));
        return NULL;
    }
    return mysql;
}
void MysqlRelease(MYSQL* mysql)//销毁句柄
{
    if (mysql)
    {
        mysql_close(mysql);
    }
    return;
}
bool MysqlQuery(MYSQL* mysql, const char* sql)//执行语句的共有接口
{
    int ret = mysql_query(mysql, sql);
    if (ret != 0)
    {
        printf("squery fild [%s] error faid:%s\n", sql, mysql_error(mysql));
        return false;
    }
    return true;
}

MYSQL* mysql = MysqlInit();
bool Insert(sensor_data & sensor)//从sensor中取出传感器信息，组指sql语句，将数据插入数据库
    {
    #define INSERT_SENSOR "insert sensor_table values(null,'%s','%s','%s');"
        int len = sensor.size() + 4096;
        char* temp = (char*)malloc(len);
        sprintf(temp, INSERT_SENSOR,
            sensor.get_name(),
            sensor.get_locat(),
            sensor.get_ip());
        bool ret = MysqlQuery(mysql, temp);
        free(temp);
        return ret;
    }

bool Delete(int sensor_id)//根据传感器id删除
{
    #define DELETE_SENSOR "delete from sensor_table where id=%d;"
    char temp[1024]={0};
    sprintf(temp,DELETE_SENSOR,sensor_id);
    bool ret=MysqlQuery(mysql,temp);
    free(temp);
    return ret;
}

 bool Update(sensor_data & sensor)//从sensor中取出信息，组指sql语句，更新数据
        {
        #define UPDATE_SENSOR "update sensor_table set name='%s',locat='%s',address='%s' where id=%d;"
        int len = sensor.size() + 4096;
        char* temp = (char*)malloc(len);
        sprintf(temp, UPDATE_SENSOR,
        sensor.get_name(),
        sensor.get_locat(),
        sensor.get_ip(),
        sensor.get_id());
        bool ret = MysqlQuery(mysql, temp);
        free(temp);
        return ret;

        }

 bool GetAll(sensor_data* sens)//通过sens返回所有的传感器信息
{
     #define GETALL_SENSOR "select *from sensor_table"

    _mutex.lock();
     bool ret=MysqlQuery(mysql,GETALL_SENSOR);//执行查询语句
     if(ret==false)
     {
        _mutex.unlock();
         return false;
     }

    MYSQL_RES *res=mysql_store_result(mysql);//保存结果集
    _mutex.unlock();
    if(res==NULL)
    {
    printf("store all blog faid error :%s\n",mysql_error(mysql));
    return false;
    }
     //遍历结果集
    int row_num=mysql_num_rows(res);

    for(int i=0;i<row_num;i++)
     {
        MYSQL_ROW row=mysql_fetch_row(res);
        sensor_data sen(0,0,0,0);
        sen.set_id(std::stoi(row[0]));
        sen.set_name(row[1]);
        sen.set_locat(row[2]);
        sen.set_ip(row[3]);
        *sens=sen;
        sens++;//添加json数组元素
    }
    mysql_free_result(res);
    return true;
   }

int main()
{
    sensor_data* sen;
	sensor_data water(19, "人体传感", "卧室", "0.0.0.2");
    //Insert(water);
    Update(water);
    //Delete(20);
    GetAll(sen);
    for(int i=0;i<=sen[i].get_id();i++)
    {
        std::cout<<sen[i].get_id()<<std::endl;
        std::cout<<sen[i].get_name()<<std::endl;
        std::cout<<sen[i].get_locat()<<std::endl;
        std::cout<<sen[i].get_ip()<<std::endl;
    }
    std::cout<<std::endl;
	return 0;
}


