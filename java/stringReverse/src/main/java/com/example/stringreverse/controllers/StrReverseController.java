package com.example.stringreverse.controllers;

import com.example.stringreverse.annotation.Counter;
import com.example.stringreverse.annotation.StrReverser;
import com.example.stringreverse.cache.Cache;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.server.ResponseStatusException;

import java.util.Map;

@Service
@RestController
public class StrReverseController {
    private final Cache cache;
    private final Counter count;
    private static final Logger logger = LoggerFactory.getLogger(StrReverseController.class);

    @Autowired
    public StrReverseController(Cache cache, Counter count) {
        this.cache = cache;
        this.count = count;
    }

    @GetMapping("/StrReverser")
    public StrReverser strReverse(@RequestParam(defaultValue = "") String str) {
        try {
            if (str.isBlank()) {
                logger.error("Input string is empty");
                throw new ResponseStatusException(HttpStatus.BAD_REQUEST, "Input string is empty");
            }
            logger.info("Count request received: string={}, result={}", str, new StrReverser(str).string());
            cache.put(str, new StrReverser(str).string());
            count.increment();
            logger.info("Number of requests = {}", count.getCount());
            return new StrReverser(str);
        } catch (ResponseStatusException e) {
            logger.error("Client error: {}", e.getMessage());
            throw e;
        } catch (Exception e) {
            logger.error("Internal server error", e);
            throw new ResponseStatusException(HttpStatus.INTERNAL_SERVER_ERROR, e.getMessage(), e);
        }
    }

    @GetMapping("/cache")
    public Map<String, String> showCache() {
        return cache.getAll();
    }

    @GetMapping("/count/requests")
    public ResponseEntity<Integer> getCount() {
        int counter = count.getCount();
        logger.info("Request count request received: count={}", counter);
        return ResponseEntity.ok(counter);
    }
}