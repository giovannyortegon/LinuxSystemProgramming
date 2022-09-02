int main() {

  var string;

  conocerTipo(string);
  string = "Giovanny";
  conocerTipo(string);

  return (0);
}

conocerTipo (dynamic variable){

  if (variable is String)
    print("Es tipo string.");
  else
    print("No se conoce el tipo de variable.");
}