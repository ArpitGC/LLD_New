package org.example;



//Adapter Pattern

/*
* payment gateway might support multiple payment processors (like Razorpay, Paytm, Stripe, etc.).
Each processor has its own API, different request formats, and different response structures.

You don’t want your core business logic to depend directly on each of these processors.
* So we use Adapter pattern here
*
*
*
*
*
*
*
* */
//class PaymentService{
//
//    void pay(){
//        RazorpayAPI.requestPay("data");
//    }
//
//}

public interface PaymentProcessorAdapter{
    ProcessorResponse processPayment(PaymentData data);

}
public class RazorpayAdapter implements PaymentProcessorAdapter {
    public ProcessorResponse processPayment(PaymentData data) {
        // convert PaymentData to Razorpay format
        RazorpayRequest rq = new RazorpayRequest(data);
        RazorpayResponse rp = RazorpayAPI.send(rq);
        return new ProcessorResponse(rp.status, rp.txnId);
    }
}


public class PaytmAdapter implements PaymentProcessorAdapter {
    public ProcessorResponse processPayment(PaymentData data) {
        // convert PaymentData to Paytm format
        PaytmRequest rq = new PaytmRequest(data);
        PaytmResponse rp = PaytmAPI.send(rq);
        return new ProcessorResponse(rp.status, rp.txnId);
    }
}

public class PaymentService {
    public void initiatePayment(PaymentRequest request) {
        PaymentProcessorAdapter adapter;

        if (request.method.equals("Razorpay"))
            adapter = new RazorpayAdapter();
        else
            adapter = new PaytmAdapter();

        ProcessorResponse res = adapter.processPayment(request.toPaymentData());
        // handle response
    }
}




//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        //TIP Press <shortcut actionId="ShowIntentionActions"/> with your caret at the highlighted text
        // to see how IntelliJ IDEA suggests fixing it.
        System.out.printf("Hello and welcome!");

        for (int i = 1; i <= 5; i++) {
            //TIP Press <shortcut actionId="Debug"/> to start debugging your code. We have set one <icon src="AllIcons.Debugger.Db_set_breakpoint"/> breakpoint
            // for you, but you can always add more by pressing <shortcut actionId="ToggleLineBreakpoint"/>.
            System.out.println("i = " + i);
        }
    }
}