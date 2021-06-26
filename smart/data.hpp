#pragma once
class sensor_data
{
public:
	sensor_data(int id, const char* name,  const char* locat, const char*ip):_id(id),_name(name),_locat(locat),_ip(ip){}
	//sensor_data(){}
	int set_id(int id) { _id = id; return 0;}
	int set_name(char* name) { _name = name; return 0;}
	int set_ip(char* ip) { _ip = ip; return 0;}
	int set_locat(char*locat) { _locat = locat;return 0; }
	int get_id() { return _id; }
	const char* get_name() { return _name;}
	const  char* get_ip() { return _ip;}
	const char* get_locat() { return _locat;}
	int size() 
	{
		return (sizeof(_id) + sizeof(_name) + sizeof(_ip) + sizeof(_locat));
	}
private:
	int _id;
	const char* _name;
	const char* _ip;
	const char* _locat;
};
// class light_data
// {
// public:
// 	light_data(int id, char* name, char* ip, char* locat)
// 	{
// 		_id = id;
// 		_name = name;
// 		_ip = ip;
// 	}
// 	//light_data() {}
// 	int set_id(int id) { _id = id; }
// 	int set_name(char* name) { _name = name; }
// 	int set_ip(char* ip) { _ip = ip; }
// 	int get_id() { return _id; }
// 	char* get_name() { return _name; }
// 	char* get_ip() { return _ip; }
// private:
// 	int _id;
// 	char* _name;
// 	char* _ip;
// };