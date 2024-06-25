// Job.cpp
#include "Job.h"

Job::Job(const std::string& jobId, JobType type, const std::string& dbName, const std::string& collectionName, int totalEntries)
    : jobId(jobId), type(type), dbName(dbName), collectionName(collectionName), totalEntries(totalEntries), status(JobStatus::Created) {}

