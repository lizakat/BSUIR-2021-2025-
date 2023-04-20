package com.example.stringreverse.annotation;
import org.springframework.stereotype.Component;

@Component
public class Counter {
    private int count = 0;

    public int increment() {
        return ++count;
    }

    public int getCount() {
        return count;
    }
}
//synchronized