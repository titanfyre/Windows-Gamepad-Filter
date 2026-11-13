import titancsa.products.windows_gamepad_filter.Interceptor;
public class Smoke { public static void main(String[] args) { try(var client=new Interceptor()){System.out.println("Packaged production DLL lazy load passed");} } }
