const db=require('../database.js');

const grade={
    getById(un,callback){
        return db.query('SELECT username, course_name,grade,date_format(grade_date,"%d.%m.%Y") as grade_date FROM grade INNER JOIN course ON course.idcourse=grade.id_course WHERE username=?',[un],callback);
    }
}

module.exports=grade;