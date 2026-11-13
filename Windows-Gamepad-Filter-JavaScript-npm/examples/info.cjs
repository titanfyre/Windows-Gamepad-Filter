const {Interceptor}=require("windows-gamepad-filter");const io=new Interceptor();try{console.log(io.info())}finally{io.close()}
