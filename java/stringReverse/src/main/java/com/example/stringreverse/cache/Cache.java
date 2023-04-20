package com.example.stringreverse.cache;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.stereotype.Component;
import org.springframework.stereotype.Service;

import java.util.HashMap;
import java.util.Map;

@Component
@Service
public class Cache {
    private static final Logger logger = LoggerFactory.getLogger(Cache.class);
    private final Map<String, String> cache = new HashMap<>();

    public void put(String key, String value) {
        logger.info("Adding value to cache: key={}, value={}", key, value);
        cache.put(key, value);
    }

    public String get(String key) {
        String value = cache.get(key);
        if (value != null) {
            logger.info("Retrieving value from cache: key={}, value={}", key, value);
        }
        return value;
    }

    public Map<String, String> getAll() {
        return new HashMap<>(cache);
    }
}
