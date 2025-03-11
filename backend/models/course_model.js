const db=require('../database.js');

const course={
    getAll(callback){
        return db.query('SELECT * FROM course',callback);
    },
    getById(id, callback){
        return db.query('SELECT * FROM course WHERE idcourse=?',[id],callback);
    },
    add(newCourse,callback){
        return db.query('INSERT INTO course(course_name, credit_points) VALUES(?,?)',[newCourse.course_name, newCourse.credit_points],callback);
    },
    update(id,newData,callback){
        return db.query('UPDATE course SET course_name=?, credit_points=? WHERE idcourse=?',
            [newData.course_name, newData.credit_points, id],callback
        );
    },
    delete(id,callback){
        return db.query('DELETE FROM course WHERE idcourse=?',
            [id],callback
        );
    }
}

module.exports=course;