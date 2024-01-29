#include <stdio.h>
#define MAX_JOBS 100
#define MAX_NAME 50
#define MAX_RESUME 100
int status,S,C;
struct Job {
char title[MAX_NAME];
char company[MAX_NAME];
int vacancies;
};

struct Applicant {
char name[MAX_NAME];
char resume[MAX_RESUME];
};

void AddVacancy(struct Job jobs[], int *numJobs) {
if (*numJobs < MAX_JOBS) {
printf("Enter job title: ");
scanf("%s", jobs[*numJobs].title);
printf("Enter company name: ");
scanf("%s", jobs[*numJobs].company);
printf("Enter number of vacancies: ");
scanf("%d", &jobs[*numJobs].vacancies);
(*numJobs)++;
printf("Job added successfully!\n");
} else {
printf("Maximum job listings reached!\n");
}
}

void DisplayVacancy(struct Job jobs[], int numJobs) {
if (numJobs > 0) {
printf("Job Listings:\n");
for (int i = 0; i < numJobs; ++i) {
printf("%d %s at %s (%d vacancies)\n", i + 1, jobs[i].title, jobs[i].company, jobs[i].vacancies);
}
} else {
printf("No job listings available!\n");
}
}

void JobApply(struct Job jobs[], int numJobs, struct Applicant applicants[], int *numApplicants) {
int jobIndex;
DisplayVacancy(jobs, numJobs);

if (numJobs > 0) {
printf("Enter the job number you want to apply for: ");
scanf("%d", &jobIndex);

if (jobIndex > 0 && jobIndex <= numJobs) {
printf("Enter your name: ");
scanf("%s", applicants[*numApplicants].name);
FILE *fp;
fp=fopen("form.docx", "w");
printf("Upload your resume: \n");
fscanf(fp, "%s", applicants[*numApplicants].resume);
jobs[jobIndex - 1].vacancies--;
(*numApplicants)++;
printf("Application submitted successfully!\n");
} else {
printf("Invalid job number!\n");
}
}
}
void application(struct Applicant applicants[], int numApplicants) {
  printf("%d  %s ",numApplicants,applicants[numApplicants].name);
}

void AppStatus()
{

  printf("1.Accepted\n 2.Rejected\n");
  scanf("%d",&status);
}

void App2Status()
{
  if(status=1)
  {
    printf("Accepted");
  }
  else
  {
    printf("Rejected");
  }
}

int main(void) {
  int N;
  char username[100], password[100];
  struct Job jobs[MAX_JOBS];
  struct Applicant applicants[MAX_JOBS];
  int numJobs = 0;
  int numApplicants = 0;


  do{
    printf(" 1.ADMIN\n 2.EMPLOYER\n 3.APPLICANT\n 4.Exit\n");
    scanf("%d", &N);
  switch (N) {
  case 1: {
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    if (strcmp(username, "Admin") == 0 && strcmp(password, "Password1") == 0) {
      printf("Login successful.\n");
    } else {
      printf("Invalid username or password.\n");
      break;
    }

   DisplayVacancy(jobs, numJobs);

    break;
  }
    case 2 : {
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    if (strcmp(username, "Employer") == 0 &&
        strcmp(password, "Password2") == 0) {
      printf("Login successful.\n");
    } else {
      printf("Invalid username or password.\n");
      break;
    }
      printf("1.Add Vacancy\n2.View Applications\n");
      scanf("%d",&S);
      if(S==1)
      {
          AddVacancy(jobs, &numJobs);
      }
      else
      {
          if (numApplicants>0)
            {
              AppStatus();
            }
    
          else
          {
            printf("No applications available\n");
          }
        numApplicants=0;
     }

    break;
  }
  case 3: {
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    if (strcmp(username, "Applicant") == 0 &&
        strcmp(password, "Password3") == 0) {
      printf("Login successful.\n");
    } else {
      printf("Invalid username or password.\n");
      break;
    }
    printf("1.Apply for a job\n2.View Application status\n");
    scanf("%d" , &C);
   
    if(C==1)
    {
      JobApply(jobs, numJobs, applicants, &numApplicants);
    }
    else
    { if(status>0)
          App2Status();
      else
        printf("Your Application is in Progress\n");
    }
    status=0;
    break;
  }
    case 4:
      {
      
        break;
      }
  }
  }while(N!=4);
  return 0;
}
