const mysql=require('mysql2');
const dotenv=require('dotenv');
dotenv.config();
const ConnectionString='mysql://peppiuser:peppipass@127.0.0.1:3306/peppidb';
//const connection=mysql.createPool(ConnectionString);
const connection=mysql.createPool(process.env.MYSQL_SERVER);

module.exports=connection;

/*
LUODAAN TUNNUS JA ANNETAAN OIKEUDET
CREATE USER peppiuser@localhost IDENTIFIED BY 'peppipass';
GRANT ALL ON peppidb.* TO  peppiuser@localhost;

*/