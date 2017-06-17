/**********************************************************************
 * @file   myHEADER.h                                                 *
 * @author IOANNIS TSIAKKAS Student at UOC csd3213                    *
 *                                                                    *
 * @brief  Header file with the structures and function prototypes    *
 * for the needs of the Data Structures (HY-240a) project (Fall 2015) *
 * Computer Science Department, University of Crete, Greece           *
**********************************************************************/
/*
// FOR buy_present.c
void printPresentsList(){
    struct present *reader = stock_list;
    
    printf("B <%d> <%d>\n\n   Presents = ",reader->pid,reader->stock_cnt);
    while (reader->pid != -1) {
        
        printf("<%d>, ",reader->pid);
        reader = reader->next;
    }
    printf("\n\nDONE\n\n");
}


// FOR letter_recieved.c
void check(int i, int cid, int age, int did, int pid1, int pid2, int pid3) {
    
    if (Age_categories[i] == NULL) {
        
        struct child* newChild = (struct child *)malloc(sizeof(struct child));
        
        newChild->cid = cid;
        newChild->age = age;
        newChild->did = did;
        newChild->next = NULL;
        newChild->present_choices[0] = pid1;
        newChild->present_choices[1] = pid2;
        newChild->present_choices[2] = pid3;
        
        Age_categories[i] = newChild;
        
    }else{//printf("KAPPA : ");
        
        struct child* reader = Age_categories[i];
        
        while (reader->next != NULL) {
            if (reader->next->cid > cid) {
                
                struct child* newChild = (struct child *)malloc(sizeof(struct child));
                
                newChild->cid = cid;
                newChild->age = age;
                newChild->did = did;
                
                newChild->present_choices[0] = pid1;
                newChild->present_choices[1] = pid2;
                newChild->present_choices[2] = pid3;
                
                newChild->next = reader->next;
                reader->next = newChild;
                
                break;
                
            }//printf("IN, ");
            reader = reader->next;
        }
        
        if (reader->next == NULL) {
            
            struct child* newChild = (struct child *)malloc(sizeof(struct child));
            
            newChild->cid = cid;
            newChild->age = age;
            newChild->did = did;
            
            newChild->present_choices[0] = pid1;
            newChild->present_choices[1] = pid2;
            newChild->present_choices[2] = pid3;
            
            newChild->next = NULL;
            reader->next = newChild;
            
        }
        
    }
}

void check_correct(int i, int cid, int age, int did, int pid1, int pid2, int pid3) {
    
    if (Age_categories[i] == NULL) {
        
        struct child* newChild = (struct child *)malloc(sizeof(struct child));
        
        newChild->cid = cid;
        newChild->age = age;
        newChild->did = did;
        newChild->next = NULL;
        newChild->present_choices[0] = pid1;
        newChild->present_choices[1] = pid2;
        newChild->present_choices[2] = pid3;
        
        Age_categories[i] = newChild;
        
    }else{
        
        //helper *node reader that gets value of front o struct
        struct child* reader = Age_categories[i];
        struct child* readerprev = NULL;
        
        while (reader != NULL) {
            
            if (reader->cid == cid) { // if present's id is found in the list than there is no reason to continue searching
                
                reader = NULL;
                
            }else{
                
                if (reader->cid < cid) { // cid is bigger so we go to the next block of the list
                    
                    readerprev = reader;
                    reader = reader->next;
                    
                    if (reader == NULL){ // All presents in list have smaller ids than current
                        // checking imidiatelly after going to next block to
                        // keep the O(1) speed
                        
                        struct child* newChild = (struct child *)malloc(sizeof(struct child));
                        
                        newChild->cid = cid;
                        newChild->age = age;
                        newChild->did = did;
                        newChild->next = NULL;
                        newChild->present_choices[0] = pid1;
                        newChild->present_choices[1] = pid2;
                        newChild->present_choices[2] = pid3;
                        
                        readerprev->next = newChild;
                        
                        reader = NULL;
                    }
                    
                }else if(reader->cid > cid) { // current id is smaller than the one in the list
                    
                    struct child* newChild = (struct child *)malloc(sizeof(struct child));
                    
                    newChild->cid = cid;
                    newChild->age = age;
                    newChild->did = did;
                    newChild->next = reader->next;
                    newChild->present_choices[0] = pid1;
                    newChild->present_choices[1] = pid2;
                    newChild->present_choices[2] = pid3;
                    
                    if (readerprev == NULL) { // if there is only one present and its id is bigger than current
                        newChild->next = Age_categories[i];
                        Age_categories[i] = newChild;
                    }else{ // if the current cid is in the middle of two ids
                        newChild->next = readerprev->next;
                        readerprev->next = newChild;
                    }
                    
                    reader = NULL;
                    
                }
            }
        }
    }
}

void Insert(int pid){
    
    struct present* newNode = (struct present *)malloc(sizeof(struct present));
    
    newNode->pid = pid;
    newNode->stock_cnt = 10;
    newNode->request_cnt = 0;
    
    newNode->next = stock_list;
    newNode->prev = stock_sentinel;
    
    stock_sentinel->prev = newNode;
    stock_list->prev = newNode;
    
    stock_list = newNode;
    
}

// FOR prepare_presents.c
void PrinDistricts(){
    
    struct district* districts = district_head;
    struct present_assign* ass;
    
    printf("P\n\n    DISTRICT:\n");
    while (districts != NULL) {
        printf("\n    <%d>\n       ASSIGNMENT: ",districts->did);
        ass = districts->assignL;
        while (ass != NULL) {
            printf("<%d, %d>, ",ass->cid,ass->pid);
            ass = ass->next;
        }
        districts = districts->next;
    }
    printf("\n\nDONE\n\n");
}

// analytics
void insertionSort(struct present* head){
    
    if (head != NULL) { // overcautiouse
        if (head->next != NULL) { // ultra overcautiouse
            struct present *key = NULL;
            struct present *i = NULL;
            struct present *j = NULL;
            j = head;
            key = head;
            
            if (j->request_cnt != -1) {
                /////////////////////
                while(j->next->request_cnt != -1){
                    
                    key = j;
                    i = j->next;
                    while(key->request_cnt != -1 && i->request_cnt > key->request_cnt){
                        key->next = i->next;
                        i->next->prev = key;
                        
                        if(key->prev == NULL){
                            i->prev = NULL;
                        }else{
                            i->prev = key->prev;
                            key->prev->next = i;
                        }
                        
                        i->next = key;
                        key->prev = i;
                        
                        if(i->prev != NULL){
                            key = i->prev;
                        }else{
                            break;
                        }
                        j = key;
                    }
                    j = j->next;
                }
                stock_list = stock_sentinel->next;
                stock_sentinel->next = stock_sentinel->prev;
                stock_sentinel->prev = stock_list;
            }
        }
    }
}

//new_season
void printAge(struct child* age){
    printf("Age = ");
    if (age == NULL) {
        printf(" NULL");
    }else{
        while (age != NULL) {
            printf("<%d>, ",age->cid);
            age = age->next;
        }
    }
    printf("\n");
}

// advanced_analytics.c
int most_famous (struct present_assign* head){
    
    int counterMOST = 0;
    int counterCMP = 0;
    
    int pidMOST = 0;
    int pidCMP = 0;
    
    // count the times of the first present
    pidMOST = head->pid;
    counterMOST++;
    
    if (head->next !=NULL) {
        head = head->next;
    }else{
        return pidMOST;
    }
    while (head->pid == pidMOST) {
        counterMOST++;
        if (head->next != NULL) {
            head = head->next;
        }else{
            return pidMOST;
        }
    }
    // count the rest and compare to pidMOST
    while (head != NULL) {
        ///////////////////////////////////////////
        pidCMP = head->pid;
        counterCMP = 1;
        
        if (head->next != NULL) {
            head = head->next;
        }else{
            if (counterMOST > counterCMP) {
                return pidMOST;
            }else{
                return pidCMP;
            }
        }
        
        while (head->pid == pidCMP) {
            counterCMP++;
            if (head->next != NULL) {
                head = head->next;
            }else{
                if (counterMOST > counterCMP) {
                    return pidMOST;
                }else{
                    return pidCMP;
                }
            }
        }
        if (counterMOST < counterCMP) {
            pidMOST = pidCMP;
        }
        if (head->next != NULL) {
            head = head->next;
        }else{
            return pidMOST;
        }
        ///////////////////////////////////////////
    }
    
    return 1;
}

void Sorter(struct district* head){
    
    while (head != NULL) {
        
        //if (head->assignL != NULL) {
        //    if (head->assignL->next != NULL) {
        
        struct present_assign* readerM = head->assignL;
        struct present_assign* readerC = NULL;
        struct present_assign* readerC_prev = NULL;
        struct present_assign* help = NULL;
        
        while (readerM != NULL) {
            readerC = head->assignL;
            readerC_prev = NULL;
            while (readerC->next != NULL) {
                if (readerC->pid > readerC->next->pid) {
                    
                    help = readerC->next;
                    if (readerC_prev != NULL) {
                        readerC_prev->next = help;
                        readerC->next = help->next;
                        help->next = readerC;
                    }else{
                        readerC->next = help->next;
                        help->next = readerC;
                        head->assignL = help;
                        break;
                    }
                    
                }
                readerC_prev = readerC;
                readerC = readerC->next;
                if (readerC == NULL) {break;}
            }
            readerM = readerM->next;
        }
        //}
        //}
        
        head = head->next;
    }
}
*/