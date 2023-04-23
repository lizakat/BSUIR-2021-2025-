package com.example.stringreverse;

import com.example.stringreverse.annotation.StrReverser;
import org.junit.jupiter.api.Test;
import org.springframework.http.HttpStatus;
import org.springframework.web.server.ResponseStatusException;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertThrows;

public class StrReverseControllerTest {
    @Test
    public void testStrReverserString() {
        assertEquals("cba", new StrReverser("abc").string());
        assertEquals("", new StrReverser("").string());
    }

}
