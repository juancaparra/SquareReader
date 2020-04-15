String inputString = "";         // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete
int vectorControl[3]= {1,2,3};
int inputVector[3]={3,0,0};
int resultVector[3]={0,0,0};
bool spaceVector[3]={false,false,false};
const int tam=3;

void setup() {
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(20);
  Serial.println("Hola");
  delay(1000);
  Read(inputVector);
  delay(1000);
  fill();
}

void loop() { 
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
  int missing[]={0,0,0};
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
