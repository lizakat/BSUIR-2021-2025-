package com.example.stringreverse.annotation;

public record StrReverser(String string) {
    public StrReverser(String string) {
        this.string = new StringBuilder(string).reverse().toString();
    }
}

