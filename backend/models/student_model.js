const db=require('../database.js');
const bcrypt=require('bcryptjs');

const student={
    getAll(callback){
        return db.query('SELECT * FROM student',callback);
    },
    getById(un, callback){
        return db.query('SELECT * FROM student WHERE username=?',[un],callback);
    },
    add(newStudent,callback){
        bcrypt.hash(newStudent.password,10,function(err,hashed_password){
            return db.query('INSERT INTO student VALUES(?,?,?,?,?,?)',
                [newStudent.username, newStudent.fname, newStudent.lname,newStudent.streetaddress,newStudent.email,hashed_password], callback)
        });
    },
    update(un,newData,callback){
        bcrypt.hash(newData.password, 10, function(err,hashed_password){
            return db.query('UPDATE student SET username=?, fname=?,lname=?,streetaddress=?, email=?, password=? WHERE username=?',
                [newData.username,newData.fname, newData.lname,newData.streetaddress, newData.email,hashed_password,un],callback
            );
        })
    },
    delete(un,callback){
        return db.query('DELETE FROM student WHERE username=?',
            [un],callback
        );
    },
    checkPassword(un,callback){
        return db.query('SELECT password FROM student WHERE username=?',[un],callback);
    }
}

module.exports=student;