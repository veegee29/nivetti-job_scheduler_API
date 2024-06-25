#include "crow.h"
#include "JobScheduler.h"
#include <iostream>

std::string statusToString(JobStatus status) {
    switch (status) {
        case JobStatus::Created: return "Created";
        case JobStatus::Running: return "Running";
        case JobStatus::Completed: return "Completed";
        case JobStatus::Failed: return "Failed";
    }
    return "Unknown";
}

int main() {
    JobScheduler scheduler;

    crow::SimpleApp app;

    // Endpoint to create a job
    CROW_ROUTE(app, "/createJob").methods(crow::HTTPMethod::Post)
    ([&scheduler](const crow::request& req) {
        auto json = crow::json::load(req.body);
        
        if (!json || !json.has("type") || !json.has("dbName") || !json.has("collectionName")) {
            return crow::response(400, "Invalid JSON");
        }

        int totalEntries = json.has("totalEntries") ? static_cast<int>(json["totalEntries"].i()) : 0;
        std::string jobId = scheduler.createJob(json["type"].s(), json["dbName"].s(), json["collectionName"].s(), totalEntries);

        return crow::response(200, jobId);
    });

    // Endpoint to get job status
    CROW_ROUTE(app, "/jobStatus/<string>").methods(crow::HTTPMethod::Get)
    ([&scheduler](const crow::request&, const std::string& jobId) {
        auto status = scheduler.getJobStatus(jobId);
        if (status == JobStatus::Failed) {
            return crow::response(404, "Job not found");
        }

        return crow::response(200, statusToString(status));
    });

    // Endpoint to delete a job
    CROW_ROUTE(app, "/deleteJob/<string>").methods("DELETE"_method)
    ([&scheduler](const crow::request& req, std::string jobId) {
        auto authToken = req.get_header_value("Authorization");

        scheduler.deleteJob(jobId);
        return crow::response(200, "Job deleted");
    });

    app.port(8080).run(); // Run on port 8080
}
