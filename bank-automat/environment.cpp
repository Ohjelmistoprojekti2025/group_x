#include "environment.h"

environment::environment() {}

QString environment::base_url()
{
    return "http://localhost:3000";
    //voidaan helposti myöhemmin vaihtaa
    //return "https://azure.mybackend.com";
}
