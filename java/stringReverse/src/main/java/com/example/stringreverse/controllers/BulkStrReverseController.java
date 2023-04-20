package com.example.stringreverse.controllers;

import com.example.stringreverse.dto.BulkParam;
import com.example.stringreverse.dto.BulkStrReverseResult;
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
    public BulkStrReverseResult bulk(@RequestBody List<BulkParam> params) {
        List<String> results = params.stream()
                .map(param -> strReverseController.strReverse(param.getString()).string())
                .collect(Collectors.toList());

        int requestCount = results.size();
        int totalCount = results.stream().mapToInt(String::length).sum();
        double avgCount = results.stream().mapToInt(String::length).average().orElse(0);
        int maxCount = results.stream().mapToInt(String::length).max().orElse(0);
        int minCount = results.stream().mapToInt(String::length).min().orElse(0);


        BulkStrReverseResult result = new BulkStrReverseResult(results, requestCount, totalCount, avgCount, maxCount, minCount);
        return result;
    }
}