const db=require('../database.js');

const course={
    getAll(callback){
        return db.query('SELECT * FROM course',callback);
    },
    getById(id, callback){
        return db.query('SELECT * FROM course WHERE idcourse=?',[id],callback);
    },
    add(newCourse,callback){
        return db.query('INSERT INTO course(course_name, credit_points) VALUES(?,?)',[newCourse.course_name, newCourse._credit_points],callback);
    }
}

module.exports=course;