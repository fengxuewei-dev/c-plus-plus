#pragma once
/**
 * 从文件中读取参数值， 用来调试使用
 * params 文件的存放路径：
*/
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>

using namespace std;

typedef float*    param_t;


#define PARAM_OPEN                  open
#define PARAM_CLOSE	                close

#define PARAM_INVALID	            ((float*)-2)

#define PARAM_NOT_FOUND             0
#define PARAM_MULTI_VAL             2
#define PARAM_HAVE_GET              1

inline static int flash_param_load() { return -1; }


static char *param_user_file = nullptr;

static const char *param_default_file = "./xml/xml1.params";
// "/home/fengxuewei/GitHub/uav_project_1/fixedWing_ws/src/lib/parameters/params/fw_throttle.params"; // 路径

static ifstream    cfgFile;
static param_t      param_handle_;

static float res_value;

static string 
trim(string& str)
{
    str.erase(0, str.find_first_not_of(" \t")); // 去掉头部空格
    str.erase(str.find_last_not_of(" \t") + 1); // 去掉尾部空格
    return str;
}

static const char *
param_get_default_file()
{
	return (param_user_file != nullptr) ? param_user_file : param_default_file;
}

static int
param_load(){
    std::cout << "  param_load()    " << std::endl;
    int res = 0;
	const char *filename = param_get_default_file();
    std::cout << "  filename:    " << filename << std::endl;
    if (!filename) {
		return flash_param_load();      // 文件不存在
	}

	cfgFile.PARAM_OPEN(filename);
    if (!cfgFile) {
		return 0;   // 文件打开失败
	}

    return 1;
}

static int
param_save(){
    cfgFile.PARAM_CLOSE();
    return 1;
}

// 获取指定参数的数据
static int param_check(const char *parameter_name){
    std::cout << "  param_check()    " << std::endl;
    int Posi;
    
    std::string tmp;
    bool isMulti{false};
    std::string res;
    uint8_t i = 0;
    
    std::cout << "3" << std::endl;
    while(cfgFile.peek() != EOF)       //循环读取每一行
    {
        getline(cfgFile, tmp);
        string line(tmp);
        string::size_type pos = line.find(':');
        if(pos==line.npos) return false;
        
        string tmpKey = line.substr(0,pos);//取=号之前
        trim(tmpKey);
            

        if(parameter_name==tmpKey)
        {
            i++;
            res = line.substr(pos+1);   trim(res);
            res_value = atoi(res.c_str());
            
            
        }
    }
    std::cout << "i = " << +i << std::endl;
    if(i == 0)        return PARAM_NOT_FOUND;
    else if(i == 1)   return PARAM_HAVE_GET;
    else              return PARAM_MULTI_VAL;
}

/**
 * Look up a parameter by name.
 *
 * @param name		The canonical name of the parameter being looked up.
 * @return		    the value for the parameter's name
 */
static param_t	param_find(const char *name){

    std::cout << "  param_find()    " << std::endl;
    param_t value;

    std::string param_name = name;
    trim(param_name);
    std::cout << "param_name " << param_name << std::endl;

    uint8_t res = param_check(param_name.c_str());

    if(1 == res){
        std::cout << "param_handle_: " << param_handle_ << std::endl;
        return param_handle_;
    }
    else if(PARAM_NOT_FOUND == res)
    {
        std::cout << "参数没有找到！"<< std::endl;
    }else
    {
        std::cout << "参数存在多定义" << std::endl;
    }
    return PARAM_INVALID;  // 参数不存在 
}

static int param_get(param_t param_handle, float& _value_){

    
    // std::cout << "name : " << name << std::endl;
    // param_t VALUE;
    // int res = param_load();
    // std::cout << " param_load res : " << res << std::endl;
    // if(1 == res){
    //     VALUE = param_find(name.c_str());
    // }else
    // {
    //     return -1;
    // }

    // if(VALUE != PARAM_INVALID)
    //     _value_ = value;
    // else
    //     return -1;

    // return 1;
    
    _value_ = res_value;
    std::cout << "( *)_value_: " << _value_ << std::endl;
    
}

// int main(void *){
//     float value = 0;
//     param_load();
//     param_get(param_find("name"), value);
//     std::cout << "value : " << value << std::endl;
//     return 0;
// }