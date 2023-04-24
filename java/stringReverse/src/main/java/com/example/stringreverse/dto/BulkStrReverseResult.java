package com.example.stringreverse.dto;

import java.util.List;

public record BulkStrReverseResult(List<String> results, int requestCount, int totalCount, double avgCount,
                                   int maxCount, int minCount) {
}