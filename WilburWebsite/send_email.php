<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") 
{
    $name = $_POST["name"];
    $email = $_POST["email"];
    $message = $_POST["message"];

    $to = "tn334@nau.com";  // Team Leads Email
    $subject = "Contact Form Submission from $name";
    $headers = "From: $email";
    
    if(mail($to, $subject, $message, $headers))
    {
        // Redirect to a thank you page or provide feedback to the user
        header("Location: thank-you.html");  // You can create a thank you page
    }

    else
    {
        echo "Error: ".error_get_last()["message"];
    }
} 
else 
{
    // Handle invalid requests
    echo "Invalid request!";
}
?>