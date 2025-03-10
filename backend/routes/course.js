const express = require('express');
const router = express.Router();
const course = require('../models/course_model');

router.get('/',function(request, response){
    course.getAll(function(err, result){
        if(err){
            response.json(err);
        }
        else{
            //palautetaan json array
            response.json(result);
        }
    })
});

router.get('/:id',function(request, response){
    course.getById(request.params.id,function(err, result){
        if(err){
            response.json(err);
        }
        else{
            //palautetaan json objekti
            response.json(result[0]);
        }
    })
});


module.exports=router;