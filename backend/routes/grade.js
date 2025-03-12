const express = require('express');
const router = express.Router();
const grade = require('../models/grade_model');

router.get('/:un',function(request,response){
    grade.getById(request.params.un, function(err, result){
        if(err){
            response.json(err);
        }
        else {
            response.json(result);
        }
    })
});

module.exports=router;