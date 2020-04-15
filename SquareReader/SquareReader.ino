String inputString = "";         // a String to hold incoming data
int vectorControl[]= {1,2,3,4,5,6,7,8,9};
int inputVector[]={1,2,0,4,5,6,7,8,9};
int resultVector[]={0,0,0,0,0,0,0,0,0};
bool spaceVector[]={false,false,false,false,false,false,false,false,false};
const int tam=9;

void setup() {
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(20);
  Serial.println("Hola");
  delay(1000);
  //Read(inputVector);
  delay(1000);
  fillOne(inputVector);
}

void loop() { 
}

void fillOne(int vin[]){
  int cont=0;
  Read(vin);
  for(int i=0;i<tam;i++){
    if(spaceVector[i]==true){
      cont++;
    }
  }
  if(cont==1){
    fill();
  }
}

void filling(){
  
  }

void fill(){
  int cont=0;
  bool coin=false;
  for(int i=0;i<tam;i++){
    if(spaceVector[i]==true){
      do{
        if(resultVector[cont]!=0){
          inputVector[i]=resultVector[cont];
          coin=true;
          resultVector[cont]=0;
        }
        cont++;
      }while(coin==false);
        cont=0;
        coin=false;
    }
    Serial.println(inputVector[i]);
  }
}

void Read(int vin[]){
  int count=0;
  bool coin=false;
  for(int i=0;i<tam;i++){
    for(int j=0;j<tam;j++){
      if(vectorControl[i]==vin[j]){
        coin=true;
      }
    }
  if(coin==false)
    resultVector[i]=vectorControl[i];
  coin=false;
  if(vin[i]==0)
    spaceVector[i]=true;
  //Serial.println("spaceVector");
  }
}
