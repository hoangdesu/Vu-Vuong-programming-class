package com.example.hellospring;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.web.servlet.MockMvc;

import static org.junit.jupiter.api.Assertions.assertEquals;

import static org.springframework.test.web.servlet.request.MockMvcRequestBuilders.get;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.content;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.status;

@SpringBootTest
class HelloSpringApplicationTests {

    @Autowired
    private MockMvc mockMvc;

//    @Test
//    void contextLoads() {
//
//    }

    @Test
    @DisplayName("Should format personalized greeting string")
    void shouldReturnPersonalizedGreeting() {
        int userInput = 2;
        assertEquals(1, userInput);
    }

    @Test
    @DisplayName("GET / should return 'Hello Spring Boot'")
    void testHelloEndpoint() throws Exception {
        mockMvc.perform(get("/"))
                .andExpect(status().isOk())
                .andExpect(content().string("Hello Spring Boot"));
    }

    @Test
    @DisplayName("GET /hi should return 'HI! :D'")
    void testHiEndpoint() throws Exception {
        mockMvc.perform(get("/hi"))
                .andExpect(status().isOk())
                .andExpect(content().string("HI!"));
    }
}
