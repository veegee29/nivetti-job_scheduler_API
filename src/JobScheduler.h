#pragma once

#include <string>
#include <unordered_map>
#include <mutex>
#include <vector>
#include <memory>
#include <queue>
#include "Logger.h"
#include "Job.h"

//enum class JobStatus { Created, Running, Completed, Failed };

class JobScheduler {
public:
    JobScheduler();

    std::string createJob(const std::string& jobType, const std::string& dbName, const std::string& collectionName, int totalEntries);
    JobStatus getJobStatus(const std::string& jobId);
    void deleteJob(const std::string& jobId);

private:
    std::unordered_map<std::string, JobStatus> jobStatuses;
    std::unordered_map<std::string, std::unique_ptr<Job>> jobs;
    std::mutex jobMutex;
    int jobALimit;
    int jobBLimit;
    Logger logger;
};

