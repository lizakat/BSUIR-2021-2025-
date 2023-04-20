package com.example.stringreverse.controllers;

import com.example.stringreverse.dto.BulkParam;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;

import java.util.List;
import java.util.stream.Collectors;

@RestController
public class BulkStrReverseController {
    private final StrReverseController strReverseController;

    @Autowired
    public BulkStrReverseController(StrReverseController strReverseController) {
        this.strReverseController = strReverseController;
    }

    @PostMapping("/bulk")
    public List<String> bulk(@RequestBody List<BulkParam> params) {
        List<String> results = params.stream()
                .map(param -> strReverseController.strReverse(param.getString()).string())
                .collect(Collectors.toList());

        return results;
    }
}