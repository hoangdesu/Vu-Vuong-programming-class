package com.example.hellospring;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class HelloController {
    @GetMapping("/")
    public String hello() {
        return "Hello Spring Boot";
    }

    @GetMapping("/hi")
    public String hi() {
        return "HI! :D";
    }
}
