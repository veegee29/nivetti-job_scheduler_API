# Job Scheduler Project

This project implements a job scheduler in C++11 that allows the creation, management, and deletion of jobs in a thread-safe manner. The scheduler supports two types of jobs: creating a collection of random numbers in a database (Job A) and averaging all the numbers from a given database (Job B). It also exposes a RESTful API for job creation and status reporting.

## Features

- **Job Types**:
  - **Job A**: Creates a collection in a database and populates it with up to 100,000 random numbers.
  - **Job B**: Averages all the numbers from a given database.
- **Job Limits**: Each job type is limited to 10 instances. If the limit is reached, new jobs cannot be created until an existing job is deleted.
- **Thread Safety**: Ensures thread-safe creation, management, and deletion of jobs. ~~(in progress)
- **RESTful API**:
  - **Create Job**: Allows creation of jobs with specified parameters.
  - **Get Job Status**: Retrieves the status and outcome of a job.
  - **Delete Job**: Allows deletion of a job by its ID.
- **Database Support**: Supports MongoDB (MongoDB Atlas for this project).~~(process is still in the progress)
- **Logging**: Logs job creation, status updates, and errors.
- **Configuration**: Uses a configuration file for setting parameters like default number of entries.

## Folder Structure

```
API/
├── src/
│   ├── Job.cpp
│   ├── JobScheduler.cpp
│   ├── Job.h
│   ├── JobScheduler.h
│   ├── Logger.h
│   ├── Logger.cpp
│   └── main.cpp
├── CMakeLists.txt
└── README.md
```

## Installation

1. **Install Dependencies**:
   - MongoDB C++ Driver
   - Boost Libraries
   - Crow (C++ microframework)

2. **Clone the Repository**:
   ```bash
   git clone https://github.com/yourusername/JobSchedulerProject.git
   cd JobSchedulerProject
   ```

3. **Build the Project**:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

## Running the Project

Run the executable:

```bash
./JobScheduler
```

The RESTful API will be available at `http://localhost:8080`.
can also host remotely with ngrok.

## API Endpoints

### Create Job

- **Endpoint**: `/createJob`
- **Method**: `POST`
- **Parameters**:
  - `type`: "A" or "B"
  - `dbName`: Database name
  - `collectionName`: Collection name
  - `totalEntries` (optional): Number of entries (default is 2024)
- **Response**: Job ID

### Get Job Status

- **Endpoint**: `/jobStatus/<jobId>`
- **Method**: `GET`
- **Parameters**: `jobId`
- **Response**: Job status (e.g., "started", "running", "exited with output")

### Delete Job

- **Endpoint**: `/deleteJob/<jobId>`
- **Method**: `DELETE`
- **Parameters**: `jobId`
- **Response**: Status message


## Testing with Postman
** Host remotely using ngrok **

1. **Import API Endpoints**:
   - Use Postman to create requests for the API endpoints.

2. **Create Job**:
   - POST to `http://localhost:8080/createJob` with JSON body:
     ```json
     {
       "type": "A",
       "dbName": "testDB",
       "collectionName": "testCollection",
       "totalEntries": 1000
     }
     ```

3. **Get Job Status**:
   - GET `http://localhost:8080/jobStatus/<jobId>`

4. **Delete Job**:
   - DELETE `http://localhost:8080/deleteJob/<jobId>`

## Example Configuration for `c_cpp_properties.json`

Here’s an example `c_cpp_properties.json` for macOS with Apple Silicon M1:

```json
{
    "configurations": [
        {
            "name": "Mac",
            "includePath": [
                "${workspaceFolder}/**",
                "/usr/local/include",
                "/opt/homebrew/include"
            ],
            "defines": [],
            "macFrameworkPath": [
                "/System/Library/Frameworks",
                "/Library/Frameworks"
            ],
            "compilerPath": "/usr/bin/clang",
            "cStandard": "c11",
            "cppStandard": "c++11",
            "intelliSenseMode": "macos-clang-arm64"
        }
    ],
    "version": 4
}
```

## Contributing

Contributions are welcome! Please fork the repository and submit pull requests.

## License

This project is licensed under the MIT License.

---
