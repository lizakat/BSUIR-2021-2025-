package com.example.stringreverse.dto;

public class BulkParam {
    private String string;
    public BulkParam() {
    }

    public BulkParam(String string) {
        this.string = string;
    }

    public String getString() {
        return string;
    }

    public void setString(String string) {
        this.string = string;
    }
}