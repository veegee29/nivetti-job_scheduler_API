#include "JobScheduler.h"
#include "Job.h"
#include <random>
#include <sstream>
#include <iostream>

std::vector<int> generateRandomNumbers(int count) {
    std::vector<int> numbers;
    srand(time(0));
    for (int i = 0; i < count; ++i) {
        numbers.push_back(rand());
    }
    return numbers;
}


JobScheduler::JobScheduler() : jobALimit(10), jobBLimit(10), logger("logs/logs.txt") {}

std::string JobScheduler::createJob(const std::string& jobType, const std::string& dbName, const std::string& collectionName, int totalEntries) {
    std::lock_guard<std::mutex> lock(jobMutex);

    if (jobType != "A" && jobType != "B") {
        return "";
    }

    if (jobs.size() >= 10) {
        std::cout << "Job limit reached. Please delete an existing job to create a new one." << std::endl;
        return "";
    }

    std::string jobId = "job_" + std::to_string(jobs.size() + 1);

    jobStatuses[jobId] = JobStatus::Created;
    // Simulate job creation and execution
    jobStatuses[jobId] = JobStatus::Running;
    // Job logic would go here
    jobStatuses[jobId] = JobStatus::Completed;
    return jobId;
}

// Implement getters and setters
void Job::execute() {
    status = JobStatus::Running;

    if (type == JobType::A) {
        // Simulate creating a collection and populating it with random numbers
        auto numbers = generateRandomNumbers(totalEntries);
        // Simulate storing the numbers in the database
    } else if (type == JobType::B) {
        // Simulate averaging numbers from the database
        // In a real scenario, fetch numbers from the collection and compute the average
    }

    status = JobStatus::Completed;
}

JobStatus JobScheduler::getJobStatus(const std::string& jobId) {
    std::lock_guard<std::mutex> lock(jobMutex);
    if (jobStatuses.find(jobId) != jobStatuses.end()) {
        return jobStatuses[jobId];
    }
    return JobStatus::Failed;
}

void JobScheduler::deleteJob(const std::string& jobId) {
    std::lock_guard<std::mutex> lock(jobMutex);
    if (jobs.find(jobId) != jobs.end()) {
        jobs.erase(jobId);
        jobStatuses.erase(jobId);
    }
}
