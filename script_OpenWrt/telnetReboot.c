

# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include<dirent.h>
# include<ctype.h>
# include<unistd.h>

int isTelnetdRunning(){
        DIR *dp;
        struct dirent *entry;
        char cmdLine[100];
        FILE *fp;

        //open "/proc" dir
        dp=opendir("/proc");
        if(dp==NULL){
                perror("opendir");
                exit(EXIT_FAILURE);
        }

        //check every process IDs
        while(entry=readdir(dp)){
                //check this is NUMdir
                if(isdigit(entry->d_name[0])){
                        char filename[100];
                        snprintf(filename,sizeof(filename),"/proc/%s/cmdline",e>

                        //open "/proc/[pid]/cmdline"
                        fp=fopen(filename,"r");

                        if(fp!=NULL){
                                fgets(cmdLine,sizeof(cmdLine),fp);

                                if(strstr(cmdLine,"telnetd")!=NULL){
                                        closedir(dp);
                                        fclose(fp);
                                        return 1;       //found telnetd process
                                }
                                fclose(fp);
                        }
                }
        }
        closedir(dp);
        return 0;       //not found telnetd process
}

int main(){
        while(1){
                if(!isTelnetdRunning()){
                system("sudo telnetd");  
                printf("start running telnetd\n");  
                }else{
                printf("telnetd is already running\n");
                }
        sleep(30);
        }
return 0;

