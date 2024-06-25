// Job.h
#pragma once

#include <string>
#include <cstdlib>
#include <ctime>
#include <sstream>



// double averageNumbers(const std::string& dbName, const std::string& collectionName) {
//     auto collection = (*client)[dbName][collectionName];
//     auto cursor = collection.find({});
//     int sum = 0;
//     int count = 0;
//     for (auto&& doc : cursor) {
//         sum += doc["number"].get_int32().value;
//         count++;
//     }
//     return static_cast<double>(sum) / count;
// }


enum class JobType { A, B };

enum class JobStatus {
    Created,
    Running,
    Completed,
    Failed
};

class Job {
private:
    std::string jobId;
    JobType type;
    std::string dbName;
    std::string collectionName;
    int totalEntries;
    JobStatus status;
    std::string id;

public:
    Job(const std::string& jobId, JobType type, const std::string& dbName, const std::string& collectionName, int totalEntries);

    // Getters
    std::string getJobId() const;
    JobType getType() const;
    std::string getDbName() const;
    std::string getCollectionName() const;
    int getTotalEntries() const;
    JobStatus getStatus() const;
    void execute();
    std::string getId() const;

    // Setters
    void setStatus(JobStatus status);
};



// JobStatus Job::getStatus() const {
//     return status;
// }
// std::string Job::getId() const {
//     return id;
// } 